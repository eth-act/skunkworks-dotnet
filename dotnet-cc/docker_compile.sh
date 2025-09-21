#!/bin/bash

set -x

mkdir -p mod_export
mkdir -p out

docker run -v ./mod_export:/runtimelab/samples/NativeLibrary/mod_export -v ./out:/runtimelab/samples/NativeLibrary/out --rm --cap-add=SYS_PTRACE --security-opt seccomp=unconfined dotnet2c

cp out/mod0.c out/mod0.h zkvm/

