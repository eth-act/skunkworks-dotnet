#include <stdio.h>
#include <stdlib.h>

#include "w2c2_base.h"
#include "wasi.h"
#include "mod0.h"
#include "wasi_snapshot_preview1.h"

void
trap(
    Trap trap
) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(trap));
    abort();
}

wasmMemory*
wasiMemory(
    void* instance
) {
    return unbundledmodule0_memory((unbundledmodule0Instance*)instance);
}

extern char** environ;

int main(int argc, char* argv[]) {
    /* Initialize WASI */
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    {
        unbundledmodule0Instance instance0;
        wasisnapshotpreview1Instance instance1;

        printf("instantiale module0...\n");
        unbundledmodule0Instantiate(&instance0, NULL);
        printf("instantiale module1...\n");
        wasisnapshotpreview1Instantiate(&instance1, NULL);

        instance0.wasip1i = &instance1;
        instance1.env__memory = instance0.m0;

        printf("start Triple(4.03)...\n");
        double y = unbundledmodule0_NativeLibrary_Triple(&instance0, 4.03);
        printf("y=%f\n", y);

        printf("nextPrime(32)...\n");
        int yy = unbundledmodule0_NativeLibrary_NextPrime(&instance0, 32);
        printf("yy=%d\n", yy);

        //printf("CalculateHash()...\n");
        //unbundledmodule0_NativeLibrary_CalculateHash(&instance0);

        unbundledmodule0FreeInstance(&instance0);
        wasisnapshotpreview1FreeInstance(&instance1);
    }

    return 0;
}
