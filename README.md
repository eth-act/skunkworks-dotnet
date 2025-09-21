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

# Current Limitations

## System.Security.Cryptography won't run

Within the dotnet runtime code classes and methods are annotated with

```
[UnsupportedOSPlatform("browser")]
```

and a `PlatformNotSupportedException` is thrown

https://github.com/dotnet/runtime/blob/80fb00f580f5b2353ff3a8aa78c5b5fd3f275a34/src/libraries/System.Security.Cryptography/src/System/Security/Cryptography/CryptoConfig.cs#L307

because of a mismatch between sync and async APIs on Browser platforms. (Why should this apply to non-browser wasm though?) A recommended workaround is to use available host functions

- github.com/dotnet/runtime/issues/73858

- github.com/dotnet/runtime/issues/82472

## tbd
