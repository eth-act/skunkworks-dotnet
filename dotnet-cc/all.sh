#!/bin/bash

set -eu

echo 'Build docker image...'
./docker_build.sh

echo 'Export artifacts and compile for amd64...'
./docker_compile.sh

echo 'Compile for rv64ima...'
make -C zkvm firmware.zkvm.elf

echo 'Run ziskemu...'
make -C zkvm debug_zkvm
