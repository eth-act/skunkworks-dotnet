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
RUN wget https://builds.dotnet.microsoft.com/dotnet/Sdk/10.0.100/dotnet-sdk-10.0.100-linux-x64.tar.gz
RUN tar xf dotnet-sdk-10.0.100-linux-x64.tar.gz
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
ENV PATH=$PATH:/wabt/bin


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
COPY nuget.pem /etc/pki/ca-trust/source/anchors/nuget.pem
RUN update-ca-trust extract
COPY examples /examples
WORKDIR /examples/basic
RUN /dotnet10/dotnet publish -r wasi-wasm
RUN wasm-tools component unbundle --module-dir mod --output Example.unbundled.wasm bin/Release/net10.0/wasi-wasm/publish/Example.wasm


### Hostfunc import

COPY ./hostfunc_patch /hostfunc_patch
RUN /hostfunc_patch/hostfunc_patch.sh


### wasm to C conversion ###

COPY amd64 /amd64
COPY zkvm /zkvm
COPY common /common
RUN w2c2 -p -m mod/unbundled-module0.wasm mod/mod0.c
WORKDIR /examples/basic/mod
RUN gcc -g -include /common/custom_shims.h -c mod0.c -D AMD64 -I/w2c2/w2c2
RUN gcc -g -c /amd64/addon.c -D AMD64 -I/w2c2/w2c2 -I/w2c2/wasi
RUN gcc -g -c /amd64/custom_imports.c
RUN gcc -g -c /amd64/main.c -D AMD64 -I. -I/w2c2/w2c2 -I/w2c2/wasi
RUN gcc -g -c /common/stubs.c -D AMD64 -I. -I/w2c2/w2c2 -I/w2c2/wasi
RUN gcc -g -c /common/wasi.c -D AMD64 -I. -I/w2c2/w2c2
WORKDIR /examples/basic
RUN /amd64/cc.sh

CMD tail -f /dev/null
