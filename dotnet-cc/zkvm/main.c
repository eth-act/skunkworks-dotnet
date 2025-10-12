#include <stdlib.h>
#include <stdio.h>

#include "w2c2_base.h"
#include "wasi.h"

#include "mod0.h"

//#define INPUT_ADDR 0xa0000000
#define INPUT_ADDR 0x90000000
#define OUTPUT_ADDR 0xa0010000

#define RAM_START 0xa0020000
#define RAM_SIZE 0x1FFE0000

#define uint32_t unsigned int
#define size_t unsigned int

wasmMemory*
wasiMemory(
	void* instance
) {
	return unbundledmodule0_memory((unbundledmodule0Instance*)instance);
}

int outputCount = 0;

// https://github.com/eth-act/skunkworks-tama/blob/main/tamaboards/zkvm/board.go
void printk(uint32_t val) {
	// TODO: This is a stub. Just write to the output address
	// Write directly to OUTPUT_ADDR
	// Format: [count:u32][data:bytes]
	// First update the count at OUTPUT_ADDR
	outputCount+=1;
	uint32_t *ptr_count = (uint32_t *)OUTPUT_ADDR;
	*ptr_count = outputCount;

	// Write the byte at OUTPUT_ADDR + 4 + (outputCount-1)
	uint32_t *ptr_val = (uint32_t *)(OUTPUT_ADDR+4+4*(outputCount-1));
	*ptr_val = val;
}

uint32_t len_input_buf() {
	uint32_t *ptr_val = (uint32_t *)(INPUT_ADDR+4*2);
	uint32_t len = (*ptr_val)/4;
	if ((*ptr_val)%4!=0) {
		len++;
	}
	return len;
}

uint32_t read_value(uint32_t i) {
	uint32_t *ptr_val = (uint32_t *)(INPUT_ADDR+4*(i+4));
	return *ptr_val;
}

// https://github.com/eth-act/skunkworks-tama/blob/main/tamaboards/zkvm/shutdown.s
void shutdown() {
	__asm__("li a7, 93");
	__asm__("ecall");
}

extern char** environ;

int main(void) {
	int test_argc = 0;
	char **test_argv = NULL;

	// Initialize WASI
	if (!wasiInit(test_argc, test_argv, environ)) {
		fprintf(stderr, "failed to init WASI\n");
		return 0;
	}

	unbundledmodule0Instance instance0;

	unbundledmodule0Instantiate(&instance0, NULL);

	//unbundledmodule0_Example_Triple(&instance0, 11);

	int y = unbundledmodule0_Example_NextPrime(&instance0, 32);
	printf("NextPrime(32)=%d\n\n\n", y);

	printf("read input values...\n");
	int32_t val = 0;
	for (int i = 0; i < len_input_buf(); i++) {
		val = read_value(i);
		printk(val);
	}
	printf("\n\n\n");

	unbundledmodule0_Example_TestCallingHostFunc(&instance0);

	unbundledmodule0FreeInstance(&instance0);

	shutdown();
}
