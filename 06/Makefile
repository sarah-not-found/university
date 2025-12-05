CC=gcc
CFLAGS=-Wall -Werror -Wextra -Wpedantic -std=c18

.PHONY: all clean

all: s06e01 s06e02 s06e03 s06e04 s06e05 args_demo
ARGS=

s06e01: s06e01.c

run: s06e01
	./s06e01 $(ARGS)
ARGS=

s06e02: s06e02.c

run: s06e02
	./s06e02 $(ARGS)
ARGS=

s06e03: s06e03.c

run: s06e03
	./s06e03 $(ARGS)
ARGS=

s06e04: s06e04.c

run: s06e04
	./s06e04 $(ARGS)
ARGS=

s06e05: s06e05.c

args_demo: args_demo.c

run: s06e05
	./s06e05 $(ARGS)
clean:
	rm s06e01 s06e02 s06e03 s06e04 s06e05 args_demo
