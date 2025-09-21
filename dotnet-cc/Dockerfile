# Use Fedora like in dotnet runtimelabs pipelines
FROM fedora:41

USER root

RUN dnf update -y && \
    dnf install -y krb5-libs libicu openssl-libs zlib git wget curl \
                   vim python3-devel gcc gcc-c++ make clang cmake \
                   file rustup gdb strace golang-go

### Setup wasi sdk 25 ###

# dotnet runtimelab also uses wasi sdk 25
WORKDIR /
RUN wget https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-25/wasi-sdk-25.0-x86_64-linux.tar.gz
RUN tar xf wasi-sdk-25.0-x86_64-linux.tar.gz
ENV WASI_SDK_PATH=/wasi-sdk-25.0-x86_64-linux
#CC="${WASI_SDK_PATH}/bin/clang --sysroot=${WASI_SDK_PATH}/share/wasi-sysroot"


### Setup dotnet10 ###

WORKDIR /
RUN mkdir /dotnet10
WORKDIR /dotnet10
RUN wget https://builds.dotnet.microsoft.com/dotnet/Sdk/10.0.100-preview.6.25358.103/dotnet-sdk-10.0.100-preview.6.25358.103-linux-x64.tar.gz
RUN tar xf dotnet-sdk-10.0.100-preview.6.25358.103-linux-x64.tar.gz
RUN ls /dotnet10


### Clone dotnet runtimelab ###

WORKDIR /
RUN git clone --single-branch --branch feature/NativeAOT-LLVM --depth 1 https://github.com/dotnet/runtimelab.git


### Setup wasmtools ###

WORKDIR /
RUN wget https://github.com/bytecodealliance/wasm-tools/releases/download/v1.236.0/wasm-tools-1.236.0-x86_64-linux.tar.gz
RUN tar xf wasm-tools-1.236.0-x86_64-linux.tar.gz
ENV PATH=$PATH:/wasm-tools-1.236.0-x86_64-linux


### Setup w2c2 ###

WORKDIR /
RUN git clone https://github.com/turbolent/w2c2.git
WORKDIR /w2c2
RUN cmake -B build
RUN cmake --build build
WORKDIR /w2c2/wasi
RUN cmake -B build
RUN cmake --build build
ENV PATH=$PATH:/w2c2/build/w2c2


### Setup wabt ###

WORKDIR /
RUN git clone --recursive https://github.com/WebAssembly/wabt.git
WORKDIR /wabt
RUN git submodule update --init
RUN mkdir /wabt/build
WORKDIR /wabt/build
RUN cmake ..
RUN cmake --build .


### Setup wasmtime ###

WORKDIR /
RUN rustup-init -y
ENV PATH=/root/.cargo/bin:$PATH
RUN git clone --recursive https://github.com/bytecodealliance/wasmtime.git
WORKDIR /wasmtime
RUN git submodule update --init
RUN cargo build


### C# to wasm conversion ###

ENV DOTNET_CLI_TELEMETRY_OPTOUT=1
WORKDIR /runtimelab/samples/NativeLibrary
COPY NativeLibrary.cs /runtimelab/samples/NativeLibrary/NativeLibrary.cs
COPY NativeLibrary.csproj /runtimelab/samples/NativeLibrary/NativeLibrary.csproj
COPY hostfunc.c /runtimelab/samples/NativeLibrary/hostfunc.c
RUN /wasi-sdk-25.0-x86_64-linux/bin/wasm32-wasi-clang -static -o mylib.dll hostfunc.c
RUN /dotnet10/dotnet publish -r wasi-wasm
RUN wasm-tools component unbundle --module-dir mod --output NativeLibrary.unbundled.wasm bin/Release/net10.0/wasi-wasm/publish/NativeLibrary.wasm
RUN mv mod/unbundled-module1.wasm mod/wasi_snapshot_preview1.wasm


### Hostfunc import

RUN mkdir -p /runtimelab/samples/NativeLibrary/hostfunc_patch
COPY ./hostfunc_patch.sh /runtimelab/samples/NativeLibrary/hostfunc_patch.sh
COPY ./hostfunc_patch/hostfunc_patch.go /runtimelab/samples/NativeLibrary/hostfunc_patch/hostfunc_patch.go
RUN cp mod/unbundled-module0.wasm mod/unbundled-module0-unpatched.wasm
RUN /wabt/bin/wasm2wat mod/unbundled-module0.wasm > mod/unbundled-module0-patched.wat
RUN ./hostfunc_patch.sh /runtimelab/samples/NativeLibrary/hostfunc_patch.sh
WORKDIR /runtimelab/samples/NativeLibrary/mod
COPY amd64/custom_imports.c /runtimelab/samples/NativeLibrary/mod/custom_imports.c
RUN gcc -g -c custom_imports.c


### wasm to C conversion ###

WORKDIR /runtimelab/samples/NativeLibrary
RUN w2c2 -p -m mod/unbundled-module0.wasm mod/mod0.c
RUN w2c2 -p -m mod/wasi_snapshot_preview1.wasm mod/wasi_snapshot_preview1.c
WORKDIR /runtimelab/samples/NativeLibrary/mod
COPY patch_code.sh /runtimelab/samples/NativeLibrary/patch_code.sh
RUN ../patch_code.sh
RUN touch /runtimelab/samples/NativeLibrary/mod/custom_shims.h
RUN gcc -g -c mod0.c -D AMD64 -I/w2c2/w2c2
RUN gcc -g -c wasi_snapshot_preview1.c -D AMD64 -I/w2c2/w2c2
COPY amd64/main.c /runtimelab/samples/NativeLibrary/mod/main.c
COPY zkvm/stubs.c /runtimelab/samples/NativeLibrary/mod/stubs.c
RUN gcc -g -c stubs.c -D AMD64 -I/w2c2/w2c2 -I/w2c2/wasi
RUN gcc -g -c main.c -D AMD64 -I/w2c2/w2c2 -I/w2c2/wasi
WORKDIR /runtimelab/samples/NativeLibrary
COPY amd64/cc.sh /runtimelab/samples/NativeLibrary/cc.sh


RUN mkdir /runtimelab/samples/NativeLibrary/out
RUN mkdir /runtimelab/samples/NativeLibrary/mod_export


CMD ./cc.sh

