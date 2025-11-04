#include <stdio.h>
#include <stdlib.h>

void unbundledmodule0_customImports__hostFuncPrintk(void* p, int b, int c) {
	printf("printk(0x%x)\n", c);
}

int unbundledmodule0_customImports__hostFuncLenInputBuf(void* p, int b, int c) {
	return 1;
}

int unbundledmodule0_customImports__hostFuncReadValue(void* p, int b, int c) {
	return 'a';
}

void unbundledmodule0_customImports__hostFuncShutdown(void* p) {
	printf("shutdown()\n");
	exit(1);
}
