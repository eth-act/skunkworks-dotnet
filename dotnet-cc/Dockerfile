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
RUN wget https://builds.dotnet.microsoft.com/dotnet/Sdk/10.0.100-rc.1.25451.107/dotnet-sdk-10.0.100-rc.1.25451.107-linux-x64.tar.gz
RUN tar xf dotnet-sdk-10.0.100-rc.1.25451.107-linux-x64.tar.gz
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
RUN mkdir /example
COPY nuget.pem /etc/pki/ca-trust/source/anchors/nuget.pem
RUN update-ca-trust extract
COPY nuget.config /example/nuget.config
COPY Example.cs /example/Example.cs
COPY Example.csproj /example/Example.csproj
WORKDIR /example
COPY hostfunc.c /example/hostfunc.c
RUN /wasi-sdk-25.0-x86_64-linux/bin/wasm32-wasi-clang -static -o mylib.dll hostfunc.c
RUN /dotnet10/dotnet publish -r wasi-wasm
RUN wasm-tools component unbundle --module-dir mod --output Example.unbundled.wasm bin/Release/net10.0/wasi-wasm/publish/Example.wasm
RUN mv mod/unbundled-module1.wasm mod/wasi_snapshot_preview1.wasm


### Hostfunc import

RUN mkdir -p /example/hostfunc_patch
COPY ./hostfunc_patch.sh /example/hostfunc_patch.sh
COPY ./hostfunc_patch/hostfunc_patch.go /example/hostfunc_patch/hostfunc_patch.go
RUN cp mod/unbundled-module0.wasm mod/unbundled-module0-unpatched.wasm
RUN /wabt/bin/wasm2wat mod/unbundled-module0.wasm > mod/unbundled-module0-patched.wat
RUN ./hostfunc_patch.sh /example/hostfunc_patch.sh
WORKDIR /example/mod
COPY amd64/custom_imports.c /example/mod/custom_imports.c
RUN gcc -g -c custom_imports.c


### wasm to C conversion ###

WORKDIR /example
RUN w2c2 -p -m mod/unbundled-module0.wasm mod/mod0.c
WORKDIR /example/mod
COPY zkvm/custom_shims.h /example/mod/custom_shims.h
RUN gcc -g -include custom_shims.h -c mod0.c -D AMD64 -I/w2c2/w2c2
COPY amd64/addon.c /example/mod/addon.c
COPY amd64/main.c /example/mod/main.c
COPY zkvm/wasi.c /example/mod/wasi.c
COPY zkvm/stubs.c /example/mod/stubs.c
RUN gcc -g -c addon.c -D AMD64 -I/w2c2/w2c2 -I/w2c2/wasi
RUN gcc -g -c stubs.c -D AMD64 -I/w2c2/w2c2 -I/w2c2/wasi
RUN gcc -g -c main.c -D AMD64 -I/w2c2/w2c2 -I/w2c2/wasi
RUN gcc -g -c wasi.c -D AMD64 -I/w2c2/w2c2
WORKDIR /example
COPY amd64/cc.sh /example/cc.sh


RUN mkdir /example/out
RUN mkdir /example/mod_export


CMD ./cc.sh

