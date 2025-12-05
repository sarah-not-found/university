CC=gcc
CFLAGS=-Wall -Werror -Wextra -Wpedantic -std=c18

.PHONY: all clean

all: s04e02_a s04e02_b s04e02_c s04e02_d s04e03 s04e03_tests

s04e02_a: s04e02_a.c

s04e02_b: s04e02_b.c

s04e02_c: s04e02_c.c

s04e02_d: s04e02_d.c

ARGS=

s04e03: s04e03.c

run: s04e03
	./s04e03 $(ARGS)
clean:
	rm s04e02_a s04e02_b s04e02_c s04e02_d s04e03
