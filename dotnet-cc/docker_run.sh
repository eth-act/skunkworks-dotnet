#!/bin/bash

set -x

mkdir -p mod_export
mkdir -p out

docker run -it -v ./mod_export:/example/mod_export -v ./out:/example/out --rm --cap-add=SYS_PTRACE --security-opt seccomp=unconfined dotnet2c bash


