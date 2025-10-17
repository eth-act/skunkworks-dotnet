#ifndef DOTNET_ZKVM_H
#define DOTNET_ZKVM_H

#include "w2c2_base.h"
#include "wasi.h"

#include <stdint.h>

//#define INPUT_ADDR 0xa0000000
#define INPUT_ADDR ((uintptr_t)0x90000000)
#define OUTPUT_ADDR ((uintptr_t)0xa0010000)

#define RAM_START 0xa0020000
#define RAM_SIZE 0x1FFE0000

#define HEAP_OFFSET 0x01000000 /* TODO */
#define HEAP_START (RAM_START+HEAP_OFFSET)
#define HEAP_SIZE (RAM_SIZE-HEAP_OFFSET)

void printk(uint32_t val);
U64 len_input_buf();
char read_value(U64* i, U64 a, U64 b);

#endif
