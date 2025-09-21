#include <stdio.h>

void unbundledmodule0_customImports__hostFuncCallback(void*, int a, int b) {
    printf("CUSTOM IMPORT(0x%x, 0x%x)\n", a, b);
}

void unbundledmodule0_customImports__printk(void* p, int b, int c) {
    printf("PRINTK(0x%x)\n", c);
}
