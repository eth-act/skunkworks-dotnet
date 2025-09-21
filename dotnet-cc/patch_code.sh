#!/bin/bash


# Correct types
sed -i 's/#include "mod0.h"/#include "custom_shims.h"\n#include "mod0.h"\n#include "wasi_snapshot_preview1.h"/' mod0.c
# Cascade type
sed -i 's/#include "w2c2_base.h"/#include "w2c2_base.h"\n#include "wasi_snapshot_preview1.h"/' mod0.h
sed -i 's/U32 g5;/U32 g5;\n  wasisnapshotpreview1Instance* wasip1i;/' mod0.h

# Make instance structs interchangeable
sed -i 's/wasmMemory\* env__memory;/wasmMemory* env__memory;\n  wasmTable t0;\n/' wasi_snapshot_preview1.h
sed -i 's/U32 g2;/U32 g2;\n  U32 g3;\n  U32 g4;\n  U32 g5;/' wasi_snapshot_preview1.h


# normalize wasip1 function names
sed -i 's/unbundledmodule0_wasi_snapshot_preview1__/wasisnapshotpreview1_/g' mod0.c
sed -i 's/unbundledmodule0_wasi_snapshot_preview1__/wasisnapshotpreview1_/g' mod0.h

# normalize wasip2 function names
sed -i 's/wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2EblockingX2DwriteX2DandX2Dflush/wasm_import_streams_method_output_stream_blocking_write_and_flush/g' *.c *.h
sed -i 's/wasisnapshotpreview1_wasiX3AcliX2FstderrX400X2E2X2E0__getX2Dstderr/wasm_import_stderr_get_stderr/g' *.c *.h
sed -i 's/wasisnapshotpreview1_wasiX3AioX2FerrorX400X2E2X2E0__X5BresourceX2DdropX5Derror/wasm_import_io_error_error_drop/g' *.c *.h
sed -i 's/wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BresourceX2DdropX5DoutputX2Dstream/wasm_import_streams_output_stream_drop/g' *.c *.h

# remove definitons from mod0.h
sed -i '/wasisnapshotpreview1_poll_oneoff/d' mod0.h
sed -i '/wasisnapshotpreview1_adapter_close_badfd/d' mod0.h
sed -i '/wasisnapshotpreview1_path_unlink_file/d' mod0.h
sed -i '/wasisnapshotpreview1_args_get/d' mod0.h
sed -i '/wasisnapshotpreview1_args_sizes_get/d' mod0.h
sed -i '/wasisnapshotpreview1_environ_get/d' mod0.h
sed -i '/wasisnapshotpreview1_environ_sizes_get/d' mod0.h
sed -i '/wasisnapshotpreview1_fd_prestat_get/d' mod0.h
sed -i '/wasisnapshotpreview1_clock_time_get/d' mod0.h
sed -i '/wasisnapshotpreview1_fd_prestat_dir_name/d' mod0.h
sed -i '/wasisnapshotpreview1_path_filestat_get/d' mod0.h
sed -i '/wasisnapshotpreview1_fd_close/d' mod0.h
sed -i '/wasisnapshotpreview1_fd_seek/d' mod0.h
sed -i '/wasisnapshotpreview1_fd_fdstat_get/d' mod0.h
sed -i '/wasisnapshotpreview1_random_get/d' mod0.h
sed -i '/wasisnapshotpreview1_sched_yield/d' mod0.h
sed -i '/wasisnapshotpreview1_fd_write/d' mod0.h
sed -i '/wasisnapshotpreview1_proc_exit/d' mod0.h

# allocate max pages from the start
sed -i 's/wasmMemoryAllocate(51, 32768, false)/wasmMemoryAllocate(51, 1<<12, false)/g' mod0.c


sed -Ei 's/(wasisnapshotpreview1_[a-zA-Z0-9_]+)\(i/\1(i->wasip1i/g' mod0.c

# custom random get
sed -i 's/U32 wasisnapshotpreview1_random_get/U32 wasisnapshotpreview1_random_get__unused/g' wasi_snapshot_preview1.c
