.PHONY: all docker-build compile run

all:
	./all.sh

docker-build:
	./docker_build.sh

compile-wasm: docker-build
	./docker_compile.sh

compile-rv64: docker-build
	make -C zkvm firmware.zkvm.elf

compile: compile-wasm compile-rv64

run: compile
	make -C zkvm debug_zkvm

clean:
	rm -f out/mod0.c out/mod0.h
	make -C zkvm clean

