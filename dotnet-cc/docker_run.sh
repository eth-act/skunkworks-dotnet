#!/bin/bash

set -x

mkdir -p mod_export
mkdir -p out

docker run -it -v ./mod_export:/runtimelab/samples/NativeLibrary/mod_export -v ./out:/runtimelab/samples/NativeLibrary/out --rm --cap-add=SYS_PTRACE --security-opt seccomp=unconfined dotnet2c bash


