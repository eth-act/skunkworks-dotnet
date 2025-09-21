.PHONY: all docker-build compile run

all:
	./all.sh

docker-build:
	./docker_build.sh

compile-wasm: docker-build
	./docker_compile.sh

compile-rv64: docker-build
	./docker_compile.sh

compile: compile-wasm compile-rv64

run: compile
	make -C zkvm debug_zkvm
