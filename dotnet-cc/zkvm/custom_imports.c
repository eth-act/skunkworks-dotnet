#include "zkvm.h"
#include <stdio.h>

// call printk directly from C# code
void unbundledmodule0_customImports__hostFuncPrintk(void* p, int b, int c) {
	printk(c);
}

U64 unbundledmodule0_customImports__hostFuncLenInputBuf(U64* p) {
	return len_input_buf();
}

extern char _stack_top[];
extern char _stack_bottom[];

int unbundledmodule0_customImports__hostFuncReadValue(U64* p, U64 b, U64 c) {
	int result = read_value(p, b, c);
	return result;
}
