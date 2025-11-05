#!/bin/bash

set -xeu


### C# to wasm conversion ###

cd /build
/dotnet10/dotnet publish -r wasi-wasm
wasm-tools component unbundle --module-dir mod --output Example.unbundled.wasm bin/Release/net10.0/wasi-wasm/publish/Example.wasm
mv mod/unbundled-module1.wasm mod/wasi_snapshot_preview1.wasm

### Hostfunc import ###

cp mod/unbundled-module0.wasm mod/unbundled-module0-unpatched.wasm
/wabt/bin/wasm2wat mod/unbundled-module0.wasm > mod/unbundled-module0-patched.wat
/hostfunc_patch/hostfunc_patch.sh


### wasm to C conversion ###

w2c2 -p -m mod/unbundled-module0.wasm mod/mod0.c

cp mod/*.wat mod/mod0.c mod/mod0.h /build
