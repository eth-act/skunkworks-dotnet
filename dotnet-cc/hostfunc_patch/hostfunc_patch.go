package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"os"
	"strings"
)

const (
	parOpen = "("
	parClose = ")"

	space = " "

	memoryStr = `"memory"`

	keywordParam = "param"

	paramStartMatch = parOpen + keywordParam
	exportMemoryMatch = parOpen + space + memoryStr
)

func extractParams(t string) (params string) {
	i := strings.Index(t, paramStartMatch)
	t = t[i+len(paramStartMatch):]
	t = strings.TrimSuffix(t, parClose)
	return t
}

func Main(in, out string, funs []string) (err error) {
	buf := make([]byte, 30*1024*1024)
	fin, err := os.Open(in)
	if err != nil { return }

	// 1st pass: gather function signatures
	params := make(map[string]string)

	scanner := bufio.NewScanner(fin)
	scanner.Buffer(buf, len(buf))
	for scanner.Scan() {
		for _, fun := range funs {
			t := scanner.Text()
			if strings.Contains(t, fun) && strings.Contains(t, paramStartMatch) {
				log.Printf("found: %v", t)
				params[fun] = extractParams(t)
			}
		}
	}
	if err := scanner.Err(); err != nil {
		return fmt.Errorf("scanner error: %w", err)
	}

	log.Printf("params: %v", params)
	fin.Close()

	// 2nd pass: write exports
	fin, err = os.Open(in)
	if err != nil {
		return fmt.Errorf("2nd pass: open %s: %w", in, err)
	}
	defer fin.Close()

	fout, err := os.Create(out)
	if err != nil {
		return fmt.Errorf("2nd pass: create %s: %w", out, err)
	}
	defer fout.Close()

	// state
	i := 0
	exportMemoryMatched := false
	// prepare scanner
	scanner = bufio.NewScanner(fin)
	scanner.Buffer(buf, len(buf))
	w := bufio.NewWriter(fout)
	for scanner.Scan() {
		t := scanner.Text()
		if err := writeText(w, t, funs); err != nil {
			return fmt.Errorf("write text: %w", err)
		}

		if i == 0 {
			for fun, param := range params {
				fmt.Fprintf(w, "(import \"customImports\" \"%s\" (func $NativeLibrary_NativeLibrary_NativeLibrary__%sOverwrite (param %s)))\n", fun, fun, param)
			}
		} else if !exportMemoryMatched && strings.Contains(t, exportMemoryMatch) {
			for fun := range params {
				fmt.Fprintf(w, "(export \"NativeLibrary_%s\" (func $NativeLibrary_NativeLibrary_NativeLibrary__%s))\n", fun, fun)
			}
		}

		i++
	}
	if err := scanner.Err(); err != nil {
		return fmt.Errorf("scanner error: %w", err)
	}
	w.Flush()

	return
}

func writeText(w *bufio.Writer, t string, funs []string) (err error) {
	for _, fun := range funs {
		if strings.Contains(t, "call $NativeLibrary_NativeLibrary_NativeLibrary__"+fun) {
			t = strings.Replace(t, "call $NativeLibrary_NativeLibrary_NativeLibrary__"+fun, "call $NativeLibrary_NativeLibrary_NativeLibrary__"+fun+"Overwrite", 1)
		}
	}
	if _, err = w.WriteString(t+"\n"); err != nil {
		return fmt.Errorf("write: %w", err)
	}
	return err
}

func main() {
	in := flag.String("in", "mod/unbundledmodule0-unpatched.wat", "input file")
	out := flag.String("out", "mod/unbundledmodule0-patched.wat", "output file")
	funsStr := flag.String("funs", "hostFuncCallback", "comma-separated list of import functions")
	flag.Parse()

	funs := strings.Split(*funsStr, ",")

	if err := Main(*in, *out, funs); err != nil {
		log.Printf("main: %v", err)
	}
}
