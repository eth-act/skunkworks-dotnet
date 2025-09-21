.PHONY: all compile run

all:
	make -C dotnet-cc all

compile:
	make -C dotnet-cc compile

run:
	make -C dotnet-cc run
