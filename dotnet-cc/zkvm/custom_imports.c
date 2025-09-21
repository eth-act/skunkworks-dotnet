#include "zkvm.h"
#include <stdio.h>

void unbundledmodule0_customImports__hostFuncCallback(void* p, int a, int b, int c) {
	printf("unbundledmodule0_customImports__hostFuncCallback(%p, %x, %x, %x)\n", p, a, b, c);
	int64_t result;

	__asm__ volatile(
		"add %0, %1, %2\n"
		: "=r"(result)  /* output */
		: "r"(b), "r"(c)  /* inputs */
		: /* no clobbers */);

	printf("  result of adding %x and %x: %x\n", b, c, result);
}

// call printk directly from C# code
void unbundledmodule0_customImports__printk(void* p, int b, int c) {
	printk(c);
}
