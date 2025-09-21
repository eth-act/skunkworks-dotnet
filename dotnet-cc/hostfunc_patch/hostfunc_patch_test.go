package main

import (
	"fmt"
	"os"
	"testing"
)

const testIn = `(module $NativeLibrary.wasm
  (type (;0;) (func (param i32)))
  (type (;1;) (func (param i32) (result i32)))
  (type (;2;) (func (param i32 i32 i32)))
  (type (;3;) (func (param i32 i32)))
  (import "wasi_snapshot_preview1" "environ_get" (func $__imported_wasi_snapshot_preview1_environ_get (type 7)))
  (import "wasi_snapshot_preview1" "environ_sizes_get" (func $__imported_wasi_snapshot_preview1_environ_sizes_get (type 7)))
  (func $NativeLibrary_NativeLibrary_NativeLibrary__hostFuncCallback (type 2) (param i32 i32 i32)
    local.get 0
    i32.const 490259
    i32.store
    local.get 0
    i32.const 4
    i32.add
    call $S_P_CoreLib_Internal_Runtime_CompilerHelpers_InteropHelpers__ThrowLazyPInvokeResolutionNotSupportedException
    drop)
  (data $.data (i32.const 562480) "\02\00\00\00...")
  (data $__modules (i32.const 2207588) "p\ab!\00"))
`

func TestMain(t *testing.T) {
	var (
		in string
		out string
	)

	fin, err := os.CreateTemp("", "testin")
	if err != nil {
		t.Fatalf("%v", err)
	}
	in = fin.Name()
	defer os.Remove(fin.Name())
	if _, err := fin.Write([]byte(testIn)); err != nil {
		t.Fatalf("%v", err)
	}
	if err := fin.Close(); err != nil {
		t.Fatalf("%v", err)
	}
	fout, err := os.CreateTemp("", "testout")
	if err != nil {
		t.Fatalf("%v", err)
	}
	out = fout.Name()
	if err := fout.Close(); err != nil {
		t.Fatalf("%v", err)
	}
	if err := Main(in, out, []string{"hostFuncCallback"}); err != nil {
		t.Fatalf("%v", err)
	}

	res, err := os.ReadFile(out)
	if err != nil {
		t.Fatalf("%v", err)
	}
	fmt.Printf("res=%s\n", res)
}
