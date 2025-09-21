# hostfunc_patch

Basic demo for host func patching. More work is needed to map parameters correctly

# Issues (TODO)

- depending on where the call happens, the number of wasm parameters varies. At a minimum additional (context?) parameters would have to be popped from the wasm stack
