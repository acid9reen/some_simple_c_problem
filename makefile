python := python3
cc := clang++
flags := -std=c++17 -O0

default: help

help:
	@echo "This id the help menu:"
	@echo "	make str.txt -> generate str.txt file"
	@echo "	make bench.out -> compile bench.cc"
	@echo "	make all -> str + bench"

all: str.txt bench.out

str.txt: string_generator.py
	$(python) $^

bench.out: bench.cc
	$(cc) $^ $(flags) -o $@
