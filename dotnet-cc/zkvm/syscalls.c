#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

#include "zkvm.h"

#define RAM_START 0xa0a20000
#define RAM_SIZE 0x1FFE0000

#define HEAP_OFFSET 0x01000000 /* TODO */
#define HEAP_START (RAM_START+HEAP_OFFSET)
#define HEAP_SIZE (RAM_SIZE-HEAP_OFFSET)

void writeuartc(const char c) {
	char *ptr_val = (char *)(0xa0000000+512);
	*ptr_val = c;
}

/*void testuart() {
	//writeuartc('a');
	const char *s = "allo worlds!!!!!\n";
	for (int i = 0; i < strlen(s); i++) {
		writeuartc(s[i]);
	}
}*/

int _write(int file, char *ptr, int len) {
    for (int i = 0; i < len; i++) {
        writeuartc(ptr[i]);
    }
    return len;
}

int _read(int file, char *ptr, int len) {
    if (file != STDIN_FILENO) {
        errno = EBADF;
        return -1;
    }

    int i;
    for (i = 0; i < len; i++) {
    }
    return i;
}

int _open(const char *name, int flags, int mode) {
    printk(0x3333333);
    return -1;
}

int _close(int file) {
    return -1;
}

int _lseek(int file, int ptr, int dir) { return 0; }

int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file) {
    return 1;
}

void* _sbrk(int incr) {
    static char *heap_end = (char*)HEAP_START;
    char *prev_heap_end = heap_end;

    if (heap_end + incr > (char*)(HEAP_START + HEAP_SIZE)) {
        errno = ENOMEM;
        return (void*) -1; // Return error
    }

    heap_end += incr;
    return (void*) prev_heap_end;
}

// Required stubs
void _exit(int code) { while (1); }
int _kill(int pid, int sig) { return -1; }
int _getpid(void) { return 1; }

/****************************************/

/* zisk syscall */

/*

like in ziskok/entrypoint/src/syscalls/mod.rs:


ziskok/entrypoint/src/syscalls/sha256f.rs
*/

struct syscall_sha256_params {
	uint64_t state; /* 256 bits = 32 bytes */
	uint64_t input; /* 512 bits = 64 bytes */
} syscall_sha256_params;

/* result is stored at the same location as the state */
void run_ziskos_syscall(int csr_addr, int addr) {
	//register
	//asm volatile ("csrs 0x805, {});
}
