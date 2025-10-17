#!/bin/bash

set -xeu

gcc -g mod/main.o mod/addon.o mod/wasi.o mod/stubs.o mod/mod0.o mod/custom_imports.o -lm
cp mod/*.wat mod/mod0.c mod/mod0.h ./out/

