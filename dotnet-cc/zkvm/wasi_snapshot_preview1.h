#ifndef wasisnapshotpreview1_H
#define wasisnapshotpreview1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "w2c2_base.h"

typedef struct wasisnapshotpreview1Instance {
  wasmModuleInstance common;
  wasmMemory* env__memory;
  wasmTable t0;

  U32 g0;
  U32 g1;
  U32 g2;
  U32 g3;
  U32 g4;
  U32 g5;
} wasisnapshotpreview1Instance;

  void wasisnapshotpreview1_wasiX3AcliX2FenvironmentX400X2E2X2E0__getX2Denvironment(void*, U32);

  void wasisnapshotpreview1_wasiX3AclocksX2FwallX2DclockX400X2E2X2E0__now(void*, U32);

  U64 wasisnapshotpreview1_wasiX3AclocksX2FmonotonicX2DclockX400X2E2X2E0__now(void*);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BresourceX2DdropX5DdirectoryX2DentryX2Dstream(void*, U32);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EgetX2Dflags(void*, U32, U32);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BresourceX2DdropX5Ddescriptor(void*, U32);

  void wasm_import_streams_output_stream_drop(void*, U32);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__filesystemX2DerrorX2Dcode(void*, U32, U32);

  void wasm_import_io_error_error_drop(void*, U32);

  void wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BresourceX2DdropX5DinputX2Dstream(void*, U32);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EstatX2Dat(void*, U32, U32, U32, U32, U32);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EunlinkX2DfileX2Dat(void*, U32, U32, U32, U32);

  U32 wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DinputX2DstreamX2Esubscribe(void*, U32);

  U32 wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2Esubscribe(void*, U32);

  U32 wasisnapshotpreview1_wasiX3AclocksX2FmonotonicX2DclockX400X2E2X2E0__subscribeX2Dduration(void*, U64);

  U32 wasisnapshotpreview1_wasiX3AclocksX2FmonotonicX2DclockX400X2E2X2E0__subscribeX2Dinstant(void*, U64);

  void wasisnapshotpreview1_wasiX3AioX2FpollX400X2E2X2E0__X5BresourceX2DdropX5Dpollable(void*, U32);

  void wasisnapshotpreview1_wasiX3AioX2FpollX400X2E2X2E0__poll(void*, U32, U32, U32);

  void wasisnapshotpreview1_wasiX3ArandomX2FrandomX400X2E2X2E0__getX2DrandomX2Dbytes(void*, U64, U32);

  void wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2EcheckX2Dwrite(void*, U32, U32);

  void wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2Ewrite(void*, U32, U32, U32, U32);

  void wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2EblockingX2Dflush(void*, U32, U32);

  U32 wasisnapshotpreview1____main_module_____cabi_realloc(void*, U32, U32, U32, U32);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FpreopensX400X2E2X2E0__getX2Ddirectories(void*, U32);

  U32 wasm_import_stderr_get_stderr(void*);

  void wasm_import_streams_method_output_stream_blocking_write_and_flush(void*, U32, U32, U32, U32);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EreadX2DviaX2Dstream(void*, U32, U64, U32);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EwriteX2DviaX2Dstream(void*, U32, U64, U32);

  void wasisnapshotpreview1_wasiX3AcliX2FterminalX2DstdinX400X2E2X2E0__getX2DterminalX2Dstdin(void*, U32);

  void wasisnapshotpreview1_wasiX3AcliX2FterminalX2DinputX400X2E2X2E0__X5BresourceX2DdropX5DterminalX2Dinput(void*, U32);

  void wasisnapshotpreview1_wasiX3AcliX2FterminalX2DstdoutX400X2E2X2E0__getX2DterminalX2Dstdout(void*, U32);

  void wasisnapshotpreview1_wasiX3AcliX2FterminalX2DoutputX400X2E2X2E0__X5BresourceX2DdropX5DterminalX2Doutput(void*, U32);

  void wasisnapshotpreview1_wasiX3AcliX2FterminalX2DstderrX400X2E2X2E0__getX2DterminalX2Dstderr(void*, U32);

  U32 wasisnapshotpreview1_wasiX3AcliX2FstdinX400X2E2X2E0__getX2Dstdin(void*);

  U32 wasisnapshotpreview1_wasiX3AcliX2FstdoutX400X2E2X2E0__getX2Dstdout(void*);

  void wasisnapshotpreview1_wasiX3AcliX2FexitX400X2E2X2E0__exit(void*, U32);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EappendX2DviaX2Dstream(void*, U32, U32);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EgetX2Dtype(void*, U32, U32);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2Estat(void*, U32, U32);

  void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EmetadataX2DhashX2Dat(void*, U32, U32, U32, U32, U32);

U32 wasisnapshotpreview1_f40(wasisnapshotpreview1Instance*);

void wasisnapshotpreview1_f41(wasisnapshotpreview1Instance*, U32, U32);

void wasisnapshotpreview1_f42(wasisnapshotpreview1Instance*, U32);

U32 wasisnapshotpreview1_f43(wasisnapshotpreview1Instance*, U32);

void wasisnapshotpreview1_f44(wasisnapshotpreview1Instance*, U32, U32, U32);

U32 wasisnapshotpreview1_f45(wasisnapshotpreview1Instance*, U32, U32, U32, U32);

U32 wasisnapshotpreview1_f46(wasisnapshotpreview1Instance*, U32, U32, U32);

void wasisnapshotpreview1_f47(wasisnapshotpreview1Instance*, U32);

void wasisnapshotpreview1_f48(wasisnapshotpreview1Instance*, U32, U32);

void wasisnapshotpreview1_f49(wasisnapshotpreview1Instance*, U32);

U32 wasisnapshotpreview1_f50(wasisnapshotpreview1Instance*, U32, U32);

U32 wasisnapshotpreview1_f51(wasisnapshotpreview1Instance*, U32, U32);

U32 wasisnapshotpreview1_f52(wasisnapshotpreview1Instance*, U32, U64, U32);

void wasisnapshotpreview1_f53(wasisnapshotpreview1Instance*, U32, U32);

U32 wasisnapshotpreview1_f54(wasisnapshotpreview1Instance*, U32);

U32 wasisnapshotpreview1_f55(wasisnapshotpreview1Instance*, U32);

U32 wasisnapshotpreview1_f56(wasisnapshotpreview1Instance*, U32, U32);

U32 wasisnapshotpreview1_f57(wasisnapshotpreview1Instance*, U32);

void wasisnapshotpreview1_f58(wasisnapshotpreview1Instance*, U32, U32);

U32 wasisnapshotpreview1_f59(wasisnapshotpreview1Instance*, U32);

void wasisnapshotpreview1_f60(wasisnapshotpreview1Instance*, U32, U32);

U32 wasisnapshotpreview1_f61(wasisnapshotpreview1Instance*, U32, U32);

U32 wasisnapshotpreview1_f62(wasisnapshotpreview1Instance*, U32, U32, U32);

void wasisnapshotpreview1_f63(wasisnapshotpreview1Instance*, U32, U32, U32);

void wasisnapshotpreview1_f64(wasisnapshotpreview1Instance*, U32, U32);

void wasisnapshotpreview1_f65(wasisnapshotpreview1Instance*, U32, U32, U32, U32);

U32 wasisnapshotpreview1_f66(wasisnapshotpreview1Instance*, U32);

void wasisnapshotpreview1_f67(wasisnapshotpreview1Instance*, U32, U32);

void wasisnapshotpreview1_f68(wasisnapshotpreview1Instance*, U32, U32, U32, U32, U32);

void wasisnapshotpreview1_f69(wasisnapshotpreview1Instance*, U32);

U32 wasisnapshotpreview1_f70(wasisnapshotpreview1Instance*, U32, U64, U32, U32);

U32 wasisnapshotpreview1_f71(wasisnapshotpreview1Instance*, U32, U32, U32, U32);

void wasisnapshotpreview1_f72(wasisnapshotpreview1Instance*, U32, U32);

void wasisnapshotpreview1_f73(wasisnapshotpreview1Instance*, U32, U32, U32, U32, U32);

U32 wasisnapshotpreview1_f74(wasisnapshotpreview1Instance*, U32, U32, U32, U32, U32);

U32 wasisnapshotpreview1_f75(wasisnapshotpreview1Instance*, U32, U32, U32);

U32 wasisnapshotpreview1_f76(wasisnapshotpreview1Instance*, U32, U32, U32, U32);

void wasisnapshotpreview1_f77(wasisnapshotpreview1Instance*, U32);

void wasisnapshotpreview1_f78(wasisnapshotpreview1Instance*, U32);

U32 wasisnapshotpreview1_f79(wasisnapshotpreview1Instance*);

U32 wasisnapshotpreview1_f80(wasisnapshotpreview1Instance*, U32, U32);

U32 wasisnapshotpreview1_f81(wasisnapshotpreview1Instance*);

void wasisnapshotpreview1_f82(wasisnapshotpreview1Instance*, U32, U32);

void wasisnapshotpreview1_f83(wasisnapshotpreview1Instance*, U32);

void wasisnapshotpreview1_f84(wasisnapshotpreview1Instance*, U32);

U32 wasisnapshotpreview1_f85(wasisnapshotpreview1Instance*);

void wasisnapshotpreview1_f86(wasisnapshotpreview1Instance*, U32);

U32 wasisnapshotpreview1_f87(wasisnapshotpreview1Instance*);

void wasisnapshotpreview1_f88(wasisnapshotpreview1Instance*, U32);

U32 wasisnapshotpreview1_f89(wasisnapshotpreview1Instance*, U32, U32, U32);

U32 wasisnapshotpreview1_f90(wasisnapshotpreview1Instance*, U32, U32, U32);

U32 wasisnapshotpreview1_f91(wasisnapshotpreview1Instance*, U32, U32, U32);

U32 wasisnapshotpreview1_f92(wasisnapshotpreview1Instance*, U32, U32, U32);

void wasisnapshotpreview1_f93(wasisnapshotpreview1Instance*, U32, U64, U64, U64, U64);

U32 wasisnapshotpreview1_f94(wasisnapshotpreview1Instance*, U32, U32, U32);

U32 wasisnapshotpreview1_f95(wasisnapshotpreview1Instance*, U32, U32, U32);

void wasisnapshotpreview1_f96(wasisnapshotpreview1Instance*);

U32 wasisnapshotpreview1_poll_oneoff(wasisnapshotpreview1Instance* i, U32 l0, U32 l1, U32 l2, U32 l3);

U32 wasisnapshotpreview1_adapter_close_badfd(wasisnapshotpreview1Instance* i, U32 l0);

U32 wasisnapshotpreview1_path_unlink_file(wasisnapshotpreview1Instance* i, U32 l0, U32 l1, U32 l2);

U32 wasisnapshotpreview1_cabi_import_realloc(wasisnapshotpreview1Instance* i, U32 l0, U32 l1, U32 l2, U32 l3);

U32 wasisnapshotpreview1_fd_seek(wasisnapshotpreview1Instance* i, U32 l0, U64 l1, U32 l2, U32 l3);

U32 wasisnapshotpreview1_fd_write(wasisnapshotpreview1Instance* i, U32 l0, U32 l1, U32 l2, U32 l3);

U32 wasisnapshotpreview1_environ_get(wasisnapshotpreview1Instance* i, U32 l0, U32 l1);

U32 wasisnapshotpreview1_environ_sizes_get(wasisnapshotpreview1Instance* i, U32 l0, U32 l1);

U32 wasisnapshotpreview1_fd_prestat_get(wasisnapshotpreview1Instance* i, U32 l0, U32 l1);

U32 wasisnapshotpreview1_clock_time_get(wasisnapshotpreview1Instance* i, U32 l0, U64 l1, U32 l2);

U32 wasisnapshotpreview1_fd_prestat_dir_name(wasisnapshotpreview1Instance* i, U32 l0, U32 l1, U32 l2);

U32 wasisnapshotpreview1_random_get(wasisnapshotpreview1Instance* i, U32 l0, U32 l1);

U32 wasisnapshotpreview1_fd_close(wasisnapshotpreview1Instance* i, U32 l0);

U32 wasisnapshotpreview1_sched_yield(wasisnapshotpreview1Instance* i);

U32 wasisnapshotpreview1_fd_fdstat_get(wasisnapshotpreview1Instance* i, U32 l0, U32 l1);

U32 wasisnapshotpreview1_path_filestat_get(wasisnapshotpreview1Instance* i, U32 l0, U32 l1, U32 l2, U32 l3, U32 l4);

void wasisnapshotpreview1_proc_exit(wasisnapshotpreview1Instance* i, U32 l0);

void wasisnapshotpreview1Instantiate(wasisnapshotpreview1Instance* instance, void* resolve(const char* module, const char* name));

void wasisnapshotpreview1FreeInstance(wasisnapshotpreview1Instance* instance);

#ifdef __cplusplus
}
#endif

#endif /* wasisnapshotpreview1_H */

