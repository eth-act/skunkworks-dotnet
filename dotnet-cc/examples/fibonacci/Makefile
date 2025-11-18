OBJS_ZKVM = main.o startup.o syscalls.o mod0.o addon.o mathfuncs.o wasi.o stubs.o custom_imports.o

run: fibonacci.bin
	ziskemu -e ./fibonacci.bin -x --max-steps 40000000000

clean:
	rm -f *.o empty.bin mod0.c mod0.h unbundled-module0-patched.wat

.PHONY: clean

include ../../zkvm/make.inc
