#include "w2c2_base.h"
#include "wasi_snapshot_preview1.h"
#include "zkvm.h"

#include <stdio.h>

wasmMemory*
wasiMemory(
	void* instance
);

void wasisnapshotpreview1Instantiate(wasisnapshotpreview1Instance* instance, void* resolve(const char* module, const char* name)) {
	printf("wasisnapshotpreview1Instantiate\n");
}

void wasisnapshotpreview1FreeInstance(wasisnapshotpreview1Instance* instance) {
	printf("wasisnapshotpreview1FreeInstance\n");
}

void wasisnapshotpreview1_proc_exit(wasisnapshotpreview1Instance* i, U32 l0) {
	printf("wasisnapshotpreview1_proc_exit\n");
}

U32 wasisnapshotpreview1_fd_prestat_get(wasisnapshotpreview1Instance* i, U32 l0, U32 l1) {
	printf("wasisnapshotpreview1_fd_prestat_get\n");
	return 0;
}

U32 wasisnapshotpreview1_fd_prestat_dir_name(wasisnapshotpreview1Instance* i, U32 l0, U32 l1, U32 l2) {
	printf("wasisnapshotpreview1_fd_prestat_dir_name\n");
	return 0;
}

U32 wasisnapshotpreview1_fd_fdstat_get(wasisnapshotpreview1Instance* i, U32 l0, U32 l1) {
	printf("wasisnapshotpreview1_fd_fdstat_get\n");
	return 0;
}

U32 wasisnapshotpreview1_path_filestat_get(wasisnapshotpreview1Instance* i, U32 l0, U32 l1, U32 l2, U32 l3, U32 l4) {
	printf("wasisnapshotpreview1_path_filestat_get\n");
	return 0;
}

U32 wasisnapshotpreview1_environ_sizes_get(wasisnapshotpreview1Instance* i, U32 l0, U32 l1) {
	printf("wasisnapshotpreview1_environ_sizes_get\n");
	return 0;
}

U32 wasisnapshotpreview1_poll_oneoff(wasisnapshotpreview1Instance* i, U32 l0, U32 l1, U32 l2, U32 l3) {
	printf("wasisnapshotpreview1_poll_oneoff\n");
	return 0;
}

U32 wasisnapshotpreview1_adapter_close_badfd(wasisnapshotpreview1Instance* i, U32 l0) {
	printf("wasisnapshotpreview1_adapter_close_badfd\n");
	return 0;
}

U32 wasisnapshotpreview1_fd_close(wasisnapshotpreview1Instance* i, U32 l0) {
	printf("wasisnapshotpreview1_fd_close\n");
	return 0;
}

U32 wasisnapshotpreview1_environ_get(wasisnapshotpreview1Instance* i, U32 l0, U32 l1) {
	printf("wasisnapshotpreview1_environ_get\n");
	return 0;
}

U32 wasisnapshotpreview1_clock_time_get(wasisnapshotpreview1Instance* i, U32 l0, U64 l1, U32 l2) {
	printf("wasisnapshotpreview1_clock_time_get\n");
	return 0;
}

U32 wasisnapshotpreview1_fd_seek(wasisnapshotpreview1Instance* i, U32 l0, U64 l1, U32 l2, U32 l3) {
	printf("wasisnapshotpreview1_fd_seek\n");
	return 0;
}

U32 wasisnapshotpreview1_sched_yield(wasisnapshotpreview1Instance* i) {
	printf("wasisnapshotpreview1_sched_yield\n");
	return 0;
}

struct iovec {
	void* iov_base;
	size_t iov_len;
};

#define WASI_ERRNO_NOMEM 48

static const size_t ciovecSize = 8;

/* use part of wasi.c from w2c2 here but avoid full implementation */
U32 wasisnapshotpreview1_fd_write(wasisnapshotpreview1Instance* i, U32 wasiFD, U32 ciovecsPointer, U32 ciovecsCount, U32 resultPointer) {
	wasmMemory* memory = wasiMemory(i);
	struct iovec* iovecs = NULL;
	I64 total = 0;
	printf("wasisnapshotpreview1_fd_write\n");

	iovecs = malloc(ciovecsCount * sizeof(struct iovec));
	if (iovecs == NULL) {
		printf("fd_write: no mem\n");
		return WASI_ERRNO_NOMEM;
	}

	/* Convert WASI ciovecs to native iovecs */
	{
		U32 ciovecIndex = 0;
		for (; ciovecIndex < ciovecsCount; ciovecIndex++) {
			U64 ciovecPointer = ciovecsPointer + ciovecIndex * ciovecSize;
			U32 bufferPointer = i32_load(memory, ciovecPointer);
			U32 length = i32_load(memory, ciovecPointer + 4);

			printf("length = %d\n", length);

			iovecs[ciovecIndex].iov_base = memory->data + bufferPointer;
			iovecs[ciovecIndex].iov_len = length;
			total += length;

			for (int i = 0; i < iovecs[ciovecIndex].iov_len; i++) {
				putchar(((char*)iovecs[ciovecIndex].iov_base)[i]);
			}
		}
	}

	/* Store the amount of written bytes at the result pointer */
	i32_store(memory, resultPointer, total);
	return 0; // success
}

U32 wasisnapshotpreview1_path_unlink_file(wasisnapshotpreview1Instance* i, U32 l0, U32 l1, U32 l2) {
	printf("wasisnapshotpreview1_path_unlink_file\n");
	return 0;
}


