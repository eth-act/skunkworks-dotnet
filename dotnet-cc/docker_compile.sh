#!/bin/bash

set -x

mkdir -p mod_export
mkdir -p out

docker run -v ./mod_export:/example/mod_export -v ./out:/example/out --rm --cap-add=SYS_PTRACE --security-opt seccomp=unconfined dotnet2c

cp out/mod0.c out/mod0.h zkvm/

