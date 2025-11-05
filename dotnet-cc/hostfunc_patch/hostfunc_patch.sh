#!/bin/bash

set -xeu -o pipefail

SOURCE_DIR=$(dirname -- "$(readlink -f -- "$BASH_SOURCE")")

/wabt/bin/wasm2wat mod/unbundled-module0-unpatched.wasm > mod/unbundled-module0-patched.wat

go run $SOURCE_DIR/hostfunc_patch.go -in mod/unbundled-module0-patched.wat -out /tmp/unbundled-module0-patched-2.wat -funs hostFuncPrintk,hostFuncLenInputBuf,hostFuncReadValue,hostFuncShutdown
cp /tmp/unbundled-module0-patched-2.wat mod/unbundled-module0-patched.wat

/wabt/bin/wat2wasm mod/unbundled-module0-patched.wat -o mod/unbundled-module0-patched.wasm
cp mod/unbundled-module0-patched.wasm mod/unbundled-module0.wasm
