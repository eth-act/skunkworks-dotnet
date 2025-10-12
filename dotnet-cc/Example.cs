using System;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;

namespace Example
{
    public class TestCode {
        public bool IsPrime(int number) {
            if (number == 1) return false;
            if (number == 2) return true;

            if (number % 2 == 0) return false;

            for (int i  = 2; i < number; i++) {
                if (number % i == 0) return false;
            }

            return true;
        }
    }

    public unsafe class Example
    {
        [UnmanagedCallersOnly(EntryPoint = "Example_Free")]
        public static void Free(void* p)
        {
            NativeMemory.Free(p);
        }

        [UnmanagedCallersOnly(EntryPoint = "Example_Triple")]
        public static int Triple(int x)
        {
            Console.WriteLine("Triple()");
            return 3*x;
        }

        [DllImport("mylib.dll")]
        private static unsafe extern void hostFuncCallback(int a, int b);

        [DllImport("mylib.dll")]
        private static unsafe extern void printk(int a);

        [UnmanagedCallersOnly(EntryPoint = "Example_NextPrime")]
        public static int NextPrime(int x)
        {
            Console.WriteLine($"NextPrime({x})");

            var testCode = new TestCode();
            for (int i = x; i < 1000; i++) {
                if (testCode.IsPrime(i)) {
                    return i;
                }
            }

            return 0;
        }

        [UnmanagedCallersOnly(EntryPoint = "Example_TestCallingHostFunc")]
        public static void TestCallingHostFunc()
        {
            Console.WriteLine("TestCallingHostFunc()\n");

			// Test host func callback
            hostFuncCallback(0x456000, 0x789);
        }

        [UnmanagedCallersOnly(EntryPoint = "Example_CalculateHash")]
        public static void CalculateHash()
        {
            Console.WriteLine("get bytes:");
            byte[] bytes = Encoding.Unicode.GetBytes("example text");
            Console.WriteLine("create sha256 instance:");
            var sha256 = SHA256.Create();
            Console.WriteLine("compute hash:");
            var hash = sha256.ComputeHash(bytes);
        }
    }
}

