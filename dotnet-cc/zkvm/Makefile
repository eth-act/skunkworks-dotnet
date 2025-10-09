PREFIX = /opt/riscv-newlib/bin/riscv64-unknown-elf-
W2C2_ROOT=/opt/w2c2/w2c2

CC = $(PREFIX)gcc
AS = $(PREFIX)as
LD = $(PREFIX)ld

# flags:
#  -Wall: there are a lot of unused labels in mod0.c
# -O2: mod0.c otherwise takes extremely long to compile
CFLAGS = -march=rv64ima -mabi=lp64 -mcmodel=medany -specs=nosys.specs -I./include -I$(W2C2_ROOT) -D__bool_true_false_are_defined
LDFLAGS_ZKVM = -T riscv64ima_zisk_zkvm_elf_linker_script.ld -nostartfiles -lm

SRCS_ZKVM = main.c syscalls.c mod0.c addon.c mathfuncs.c wasi.c stubs.c custom_imports.c
OBJS_ZKVM = main.o startup.o syscalls.o mod0.o addon.o mathfuncs.o wasi.o stubs.o custom_imports.o

firmware.zkvm.elf: $(OBJS_ZKVM) riscv64ima_zisk_zkvm_elf_linker_script.ld
	$(CC) $(CFLAGS) $(LDFLAGS_ZKVM) $(LDFLAGS_EXTRA) -o $@ $(OBJS_ZKVM)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) firmware.elf firmware.zkvm.elf qemu_debug.log *.o

debug_zkvm: firmware.zkvm.elf
	ziskemu -e ./firmware.zkvm.elf
