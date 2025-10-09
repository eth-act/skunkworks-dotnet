#!/bin/bash


# Correct types
sed -i 's/^#include "mod0.h"$/#include "custom_shims.h"\n#include "mod0.h"\n/' mod0.c

# normalize wasip1 function names
sed -i 's/unbundledmodule0_wasi_snapshot_preview1__/wasisnapshotpreview1_/g' mod0.c
sed -i 's/unbundledmodule0_wasi_snapshot_preview1__/wasisnapshotpreview1_/g' mod0.h

# normalize wasip2 function names
sed -i 's/wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2EblockingX2DwriteX2DandX2Dflush/wasm_import_streams_method_output_stream_blocking_write_and_flush/g' *.c *.h
sed -i 's/wasisnapshotpreview1_wasiX3AcliX2FstderrX400X2E2X2E0__getX2Dstderr/wasm_import_stderr_get_stderr/g' *.c *.h
sed -i 's/wasisnapshotpreview1_wasiX3AioX2FerrorX400X2E2X2E0__X5BresourceX2DdropX5Derror/wasm_import_io_error_error_drop/g' *.c *.h
sed -i 's/wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BresourceX2DdropX5DoutputX2Dstream/wasm_import_streams_output_stream_drop/g' *.c *.h
