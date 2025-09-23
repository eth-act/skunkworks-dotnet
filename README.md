# skunkworks-dotnet

## Prerequisites

* Docker
* Rust toolchain (for building emulator)
* Make
* GNU toolchain for RISC-V in `/opt/riscv-newlib`
* w2c2 in `/opt/w2c2/w2c2`

### GNU toolchain for RISC-V

```
git clone https://github.com/riscv/riscv-gnu-toolchain
cd riscv-gnu-toolchain
sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip python3-tomli libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev
./configure --prefix=/opt/riscv-newlib --with-arch=rv64ima --disable-gdb --with-cmodel=medany
sudo make -j 8
```

#### Troubleshooting

If `make` fails to recursively clone needed submodules, try `git clone --recursive https://github.com/riscv/riscv-gnu-toolchain` instead. This takes significantly longer though

### w2c2

```
cd /opt
git clone https://github.com/turbolent/w2c2.git
```

## Building

### Build and run Everything


```
make all
```

#### With custom input file

```
cd dotnet-cc
make -C zkvm firmware.zkvm.elf
ziskemu -e ./zkvm/firmware.zkvm.elf -i test_input.dat
```

### Step-by-step calls

#### Build docker image

```
./docker_build.sh
```

#### Export artifacts and compile for amd64

```
./docker_compile.sh
```

#### Interactively start docker image

Useful for debugging and checking the intermediate result

```
./docker_run.sh
./cc.sh
./a.out
```

## Memory

wasmAllocate allocates by default a max of 1<<12=4096 pages (min 51 possible)
with each page having 65536 (1<<16) bytes.

Multiplied that's in total 250 MB.

The memory-mapped I/O regions for the target are (TODO):

- **Input Buffer** at `0x90000000` - Where input data is placed for the program
- **System Address** at `0xa0000000` (= `RAM_ADDR` = `REG_FIRST`) - Contains system address
- **UART Address** at `SYS_ADDR + 512` - Single bytes written here will be copied to the standard output
- **Output Buffer** at `0xa0010000` - Where programs write output data
- **RAM** starting at `0xa0020000` - Main memory for program execution (~512MB)

zisk/core/src/mem.rs

## Maintainability of Components

### dotnet 10

Currently there's only a release candidate with the full release scheduled end of 2025.
It's also an LTS release and supported until end of 2028.

https://dotnet.microsoft.com/en-us/platform/support/policy/dotnet-core

Additionally it includes various performance improvements compared to previous versions.

https://devblogs.microsoft.com/dotnet/performance-improvements-in-net-10/

### Wasm platform

Wasm develops rapidly with the 3.0 standard being completed in September 2025. dotnet 9 und 10
emit code for Wasm 2.0 while most tooling like runtimes and utilities still only support Wasm 1.0.

While this is bad for maintenance, this might even out since it's an open standard with a large
and active community.

But generally it might make sense to limit dependencies.

#### Official tools

https://github.com/bytecodealliance/wasm-tools

https://github.com/WebAssembly/wabt

### Microsoft.DotNet.ILCompiler

The dotnet Native AOT LLVM compiler is developed as a branch of the dotnet Runtime Lab project.
It seems to have a consistent activity with a few commits per month. The previous experiment
Native AOT for Linux and Windows has been finished and is now part of upstream dotnet.

The compiler is provided as a nuget package on https://www.nuget.org/packages/Microsoft.DotNet.ILCompiler/
and on Github in a separate branch https://github.com/dotnet/runtimelab/tree/feature/NativeAOT-LLVM

Usage is mixed in both active and now archived projects.

Also it should be mentioned that there is the somewhat similar Blazor Project targeting ASP.Net with
WebAssembly. Should Microsoft drop the Native AOT LLVM experiment it may be possible to use Blazor for
compilation with extra steps.

https://dotnet.microsoft.com/en-us/apps/aspnet/web-apps/blazor

### w2c2

w2c2 is in active development and usage. Also there are blog articles about it and various forks.

While supporting WASM and WASI, WASM 2.0/wasip2 modules are extracted in a separate build step.

https://github.com/turbolent/w2c2

## Current Limitations

### System.Security.Cryptography won't run

Within the dotnet runtime code classes and methods are annotated with

```
[UnsupportedOSPlatform("browser")]
```

and a `PlatformNotSupportedException` is thrown

https://github.com/dotnet/runtime/blob/80fb00f580f5b2353ff3a8aa78c5b5fd3f275a34/src/libraries/System.Security.Cryptography/src/System/Security/Cryptography/CryptoConfig.cs#L307

because of a mismatch between sync and async APIs on Browser platforms. (Why should this apply to non-browser wasm though?) A recommended workaround is to use available host functions

- https://github.com/dotnet/runtime/issues/73858

- https://github.com/dotnet/runtime/issues/82472

### tbd
