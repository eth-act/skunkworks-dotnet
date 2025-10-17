using System;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;

namespace Example
{
    public unsafe class Example
    {
        [UnmanagedCallersOnly(EntryPoint = "Example_Free")]
        public static void Free(void* p)
        {
            NativeMemory.Free(p);
        }

        // Host functions need to be wrapped within Unmanaged Code
        // as this is the code which can be patched on a wasm level.
        //
        // The managed code on the other hand is compiled to dotnet
        // byte code, and embedded as a binary blob.

        private static unsafe extern void hostFuncPrintk(int a);

        private static unsafe extern int hostFuncLenInputBuf();

        private static unsafe extern int hostFuncReadValue(int i);

        [UnmanagedCallersOnly(EntryPoint = "Example_hostFuncPrintkWrapper")]
        private static void hostFuncPrintkWrapper(int a) {
            hostFuncPrintk(a);
        }

        [UnmanagedCallersOnly(EntryPoint = "Example_hostFuncLenInputBufWrapper")]
        private static int hostFuncLenInputBufWrapper() {
            return hostFuncLenInputBuf();
        }

        [UnmanagedCallersOnly(EntryPoint = "Example_hostFuncReadValueWrapper")]
        private static int hostFuncReadValueWrapper(int i) {
            return hostFuncReadValue(i);
        }

        private static delegate* unmanaged<int> lenInputBuf = &hostFuncLenInputBufWrapper;
        private static delegate* unmanaged<int, int> readValue = &hostFuncReadValueWrapper;
        private static delegate* unmanaged<int, void> printk = &hostFuncPrintkWrapper;

        private static byte[] inputData() {
            int n = lenInputBuf();
            byte[] result = new byte[n];

            for (int i = 0; i < n; i++) {
                result[i] = (byte) readValue(i);
            }

            return result;
        }

        [UnmanagedCallersOnly(EntryPoint = "Example_Run")]
        public static void Run()
        {
            Console.WriteLine("Run()");

            Console.WriteLine($"input data: {Encoding.UTF8.GetString(inputData())}");
            Console.WriteLine("input data byte representation:");
            foreach (byte b in inputData()) {
                printk(b);
            }
        }
    }
}

