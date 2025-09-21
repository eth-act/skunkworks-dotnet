#!/bin/bash

set -xeu

gcc -g mod/main.o mod/stubs.o mod/mod0.o mod/wasi_snapshot_preview1.o mod/custom_imports.o -lm /w2c2/build/wasi/libw2c2wasi.a
cp mod/mod0.c mod/mod0.h ./out/

