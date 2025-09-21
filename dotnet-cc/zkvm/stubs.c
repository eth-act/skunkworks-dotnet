#include "w2c2_base.h"
#include "mod0.h"
#include "wasi_snapshot_preview1.h"
#include <stdio.h>
#include <string.h>

U32 unbundledmodule0_wasiX3AclocksX2FmonotonicX2DclockX400X2E2X2E0__subscribeX2Dduration(void*, U64) {
	printf("unbundledmodule0_wasiX3AclocksX2FmonotonicX2DclockX400X2E2X2E0__subscribeX2Dduration()\n");
}

void unbundledmodule0_wasiX3AioX2FpollX400X2E2X2E0__X5BresourceX2DdropX5Dpollable(void*, U32) {
	printf("unbundledmodule0_wasiX3AioX2FpollX400X2E2X2E0__X5BresourceX2DdropX5Dpollable()\n");
}

void unbundledmodule0_wasiX3AioX2FpollX400X2E2X2E0__poll(void*, U32, U32, U32) {
	printf("unbundledmodule0_wasiX3AioX2FpollX400X2E2X2E0__poll()\n");
}

U32 unbundledmodule0_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DinputX2DstreamX2Esubscribe(void*, U32) {
	printf("unbundledmodule0_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DinputX2DstreamX2Esubscribe()\n");
}

U32 unbundledmodule0_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2Esubscribe(void*, U32) {
	printf("unbundledmodule0_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2Esubscribe()\n");
}

void unbundledmodule0_wasiX3AioX2FstreamsX400X2E2X2E0__X5BresourceX2DdropX5DinputX2Dstream(void*, U32) {
	printf("unbundledmodule0_wasiX3AioX2FstreamsX400X2E2X2E0__X5BresourceX2DdropX5DinputX2Dstream()\n");
}

void unbundledmodule0_wasiX3AioX2FstreamsX400X2E2X2E0__X5BresourceX2DdropX5DoutputX2Dstream(void*, U32) {
	printf("unbundledmodule0_wasiX3AioX2FstreamsX400X2E2X2E0__X5BresourceX2DdropX5DoutputX2Dstream()\n");
}

void unbundledmodule0_wasiX3AsocketsX2FtcpX400X2E2X2E0__X5BmethodX5DtcpX2DsocketX2EfinishX2Dconnect(void*, U32, U32) {
	printf("unbundledmodule0_wasiX3AsocketsX2FtcpX400X2E2X2E0__X5BmethodX5DtcpX2DsocketX2EfinishX2Dconnect()\n");
}

void unbundledmodule0_wasiX3AsocketsX2FtcpX400X2E2X2E0__X5BresourceX2DdropX5DtcpX2Dsocket(void*, U32) {
	printf("unbundledmodule0_wasiX3AsocketsX2FtcpX400X2E2X2E0__X5BresourceX2DdropX5DtcpX2Dsocket()\n");
}

void unbundledmodule0_wasiX3AsocketsX2FudpX400X2E2X2E0__X5BresourceX2DdropX5DincomingX2DdatagramX2Dstream(void*, U32) {
	printf("unbundledmodule0_wasiX3AsocketsX2FudpX400X2E2X2E0__X5BresourceX2DdropX5DincomingX2DdatagramX2Dstream()\n");
}

void unbundledmodule0_wasiX3AsocketsX2FudpX400X2E2X2E0__X5BresourceX2DdropX5DoutgoingX2DdatagramX2Dstream(void*, U32) {
	printf("unbundledmodule0_wasiX3AsocketsX2FudpX400X2E2X2E0__X5BresourceX2DdropX5DoutgoingX2DdatagramX2Dstream()\n");
}

void unbundledmodule0_wasiX3AsocketsX2FudpX400X2E2X2E0__X5BresourceX2DdropX5DudpX2Dsocket(void*, U32) {
	printf("unbundledmodule0_wasiX3AsocketsX2FudpX400X2E2X2E0__X5BresourceX2DdropX5DudpX2Dsocket()\n");
}

void wasisnapshotpreview1____main_module______start(void* i) {
	printf("wasisnapshotpreview1____main_module______start()\n");
}

U32 wasisnapshotpreview1____main_module_____cabi_realloc(void* i, U32 old_ptr, U32 old_len, U32 align, U32 new_len) {
	U32 res = 0;
	printf("wasisnapshotpreview1____main_module_____cabi_realloc(%p, old_ptr=%d, old_len=%d, align=%d, new_len=%d)\n", i, old_ptr, old_len, align, new_len);
	res = unbundledmodule0_cabi_realloc(i, old_ptr, old_len, align, new_len);
	printf("	res=%x\n", res);
	return res;
}

void wasisnapshotpreview1_wasiX3AcliX2FenvironmentX400X2E2X2E0__getX2Darguments(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AcliX2FenvironmentX400X2E2X2E0__getX2Darguments()\n");
}

void wasisnapshotpreview1_wasiX3AcliX2FenvironmentX400X2E2X2E0__getX2Denvironment(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AcliX2FenvironmentX400X2E2X2E0__getX2Denvironment()\n");
}

void wasisnapshotpreview1_wasiX3AcliX2FexitX400X2E2X2E0__exit(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AcliX2FexitX400X2E2X2E0__exit()\n");
}

U32 wasm_import_stderr_get_stderr(void*) {
	printf("wasm_import_stderr_get_stderr()\n");
}

U32 wasisnapshotpreview1_wasiX3AcliX2FstdinX400X2E2X2E0__getX2Dstdin(void*) {
	printf("wasisnapshotpreview1_wasiX3AcliX2FstdinX400X2E2X2E0__getX2Dstdin()\n");
}

U32 wasisnapshotpreview1_wasiX3AcliX2FstdoutX400X2E2X2E0__getX2Dstdout(void*) {
	printf("wasisnapshotpreview1_wasiX3AcliX2FstdoutX400X2E2X2E0__getX2Dstdout()\n");
}

void wasisnapshotpreview1_wasiX3AcliX2FterminalX2DinputX400X2E2X2E0__X5BresourceX2DdropX5DterminalX2Dinput(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AcliX2FterminalX2DinputX400X2E2X2E0__X5BresourceX2DdropX5DterminalX2Dinput()\n");
}

void wasisnapshotpreview1_wasiX3AcliX2FterminalX2DoutputX400X2E2X2E0__X5BresourceX2DdropX5DterminalX2Doutput(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AcliX2FterminalX2DoutputX400X2E2X2E0__X5BresourceX2DdropX5DterminalX2Doutput()\n");
}

void wasisnapshotpreview1_wasiX3AcliX2FterminalX2DstderrX400X2E2X2E0__getX2DterminalX2Dstderr(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AcliX2FterminalX2DstderrX400X2E2X2E0__getX2DterminalX2Dstderr()\n");
}

void wasisnapshotpreview1_wasiX3AcliX2FterminalX2DstdinX400X2E2X2E0__getX2DterminalX2Dstdin(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AcliX2FterminalX2DstdinX400X2E2X2E0__getX2DterminalX2Dstdin()\n");
}

void wasisnapshotpreview1_wasiX3AcliX2FterminalX2DstdoutX400X2E2X2E0__getX2DterminalX2Dstdout(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AcliX2FterminalX2DstdoutX400X2E2X2E0__getX2DterminalX2Dstdout()\n");
}

U64 wasisnapshotpreview1_wasiX3AclocksX2FmonotonicX2DclockX400X2E2X2E0__now(void*) {
	printf("wasisnapshotpreview1_wasiX3AclocksX2FmonotonicX2DclockX400X2E2X2E0__now()\n");
}

U32 wasisnapshotpreview1_wasiX3AclocksX2FmonotonicX2DclockX400X2E2X2E0__subscribeX2Dduration(void*, U64) {
	printf("wasisnapshotpreview1_wasiX3AclocksX2FmonotonicX2DclockX400X2E2X2E0__subscribeX2Dduration()\n");
}

U32 wasisnapshotpreview1_wasiX3AclocksX2FmonotonicX2DclockX400X2E2X2E0__subscribeX2Dinstant(void*, U64) {
	printf("wasisnapshotpreview1_wasiX3AclocksX2FmonotonicX2DclockX400X2E2X2E0__subscribeX2Dinstant()\n");
}

void wasisnapshotpreview1_wasiX3AclocksX2FwallX2DclockX400X2E2X2E0__now(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AclocksX2FwallX2DclockX400X2E2X2E0__now()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FpreopensX400X2E2X2E0__getX2Ddirectories(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FpreopensX400X2E2X2E0__getX2Ddirectories()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EappendX2DviaX2Dstream(void*, U32, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EappendX2DviaX2Dstream()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EgetX2Dflags(void*, U32, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EgetX2Dflags()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EgetX2Dtype(void*, U32, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EgetX2Dtype()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EmetadataX2DhashX2Dat(void*, U32, U32, U32, U32, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EmetadataX2DhashX2Dat()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EreadX2DviaX2Dstream(void*, U32, U64, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EreadX2DviaX2Dstream()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EstatX2Dat(void*, U32, U32, U32, U32, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EstatX2Dat()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2Estat(void*, U32, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2Estat()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EunlinkX2DfileX2Dat(void*, U32, U32, U32, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EunlinkX2DfileX2Dat()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EwriteX2DviaX2Dstream(void*, U32, U64, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BmethodX5DdescriptorX2EwriteX2DviaX2Dstream()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BresourceX2DdropX5Ddescriptor(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BresourceX2DdropX5Ddescriptor()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BresourceX2DdropX5DdirectoryX2DentryX2Dstream(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__X5BresourceX2DdropX5DdirectoryX2DentryX2Dstream()\n");
}

void wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__filesystemX2DerrorX2Dcode(void*, U32, U32) {
	printf("wasisnapshotpreview1_wasiX3AfilesystemX2FtypesX400X2E2X2E0__filesystemX2DerrorX2Dcode()\n");
}

void wasm_import_io_error_error_drop(void* instance, U32 handle) {
	printf("wasm_import_io_error_error_drop(instance=%p, handle=%d)\n", instance, handle);
}

void wasisnapshotpreview1_wasiX3AioX2FpollX400X2E2X2E0__X5BresourceX2DdropX5Dpollable(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AioX2FpollX400X2E2X2E0__X5BresourceX2DdropX5Dpollable()\n");
}

void wasisnapshotpreview1_wasiX3AioX2FpollX400X2E2X2E0__poll(void*, U32, U32, U32) {
	printf("wasisnapshotpreview1_wasiX3AioX2FpollX400X2E2X2E0__poll()\n");
}

U32 wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DinputX2DstreamX2Esubscribe(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DinputX2DstreamX2Esubscribe()\n");
}

void wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2EblockingX2Dflush(void*, U32, U32) {
	printf("wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2EblockingX2Dflush()\n");
}

/*
blocking-write-and-flush: func(
   contents: list<u8>
) -> result<_, stream-error>;
github.com/WebAssembly/wasi-io/blob/main/wit/streams.wit#L165

void __wasm_import_streams_method_output_stream_blocking_write_and_flush(
  int32_t, int32_t, int32_t, int32_t
)
github.com/WebAssembly/wasi-libc/blob/main/libc-bottom-half/sources/wasip2.c
*/
void wasm_import_streams_method_output_stream_blocking_write_and_flush(void* instance, U32 self___handle, U32 contents_ptr, U32 contents_len, U32 ptr) {
	printf("wasm_import_streams_method_output_stream_blocking_write_and_flush(%p, self___handle=%d, contents_ptr=%d, contents_len=%d, ptr=%d)\n", instance, self___handle, contents_ptr, contents_len, ptr);
	wasisnapshotpreview1Instance* i1 = (wasisnapshotpreview1Instance*)instance;
	printf("write-and-flush: ");
	for (U32 i = 0; i < contents_len; i++) {
		U8 ch = i32_load8_u(i1->env__memory, (U64)(contents_ptr+i));
		if (ch != 0) {
			printf("%c", ch);
		} else {
		  printf("<%04x>", ch);
		}
	}
	printf("\n");
}

void wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2EcheckX2Dwrite(void*, U32, U32) {
	printf("wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2EcheckX2Dwrite()\n");
}

U32 wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2Esubscribe(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2Esubscribe()\n");
}

void wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2Ewrite(void*, U32, U32, U32, U32) {
	printf("wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BmethodX5DoutputX2DstreamX2Ewrite()\n");
}

void wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BresourceX2DdropX5DinputX2Dstream(void*, U32) {
	printf("wasisnapshotpreview1_wasiX3AioX2FstreamsX400X2E2X2E0__X5BresourceX2DdropX5DinputX2Dstream()\n");
}

void wasm_import_streams_output_stream_drop(void*, U32 handle) {
	printf("wasm_import_streams_output_stream_drop()\n");
}

void wasisnapshotpreview1_wasiX3ArandomX2FrandomX400X2E2X2E0__getX2DrandomX2Dbytes(void* instance, U64 buf_len, U32 buf_ptr) {
	printf("wasisnapshotpreview1_wasiX3ArandomX2FrandomX400X2E2X2E0__getX2DrandomX2Dbytes(%p, buf_ptr=%d, buf_len=%d)\n", instance, buf_ptr, buf_len);
}

/* wasip1 */

U32 wasisnapshotpreview1_random_get(wasisnapshotpreview1Instance* i1, U32 buf_ptr, U32 buf_len) {
  printf("wasisnapshotpreview1_random_get(%p, buf_ptr=%d, buf_len=%d)\n", i1, buf_ptr, buf_len);
  for (U32 i = 0; i < buf_len; i++) {
	i32_store8(i1->env__memory, (U64)(buf_ptr+i), (U8)i);
  }
  return 0;
}
