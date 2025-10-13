.PHONY: all build-zisk compile run

ZISK_DIR = zisk
ZISKEMU = $(ZISK_DIR)/target/release/ziskemu

all: build-zisk build-dotnet-cc run

build-zisk:
	cd $(ZISK_DIR) && cargo build --release -p ziskemu
	@cd $(ZISK_DIR) && export ZISKEMU=$$(pwd)/target/release/ziskemu && echo "ZISKEMU set to: $$ZISKEMU"

build-dotnet-cc:
	make -C dotnet-cc compile

run:
	make -C dotnet-cc run
