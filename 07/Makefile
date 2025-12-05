CC=gcc
CFLAGS=-Wall -Werror -Wextra -Wpedantic -std=c18

.PHONY: all clean

all: s07e01 s07e03 s07e06
ARGS=

s07e01: s07e01.c

run: s07e01
	./s07e01 $(ARGS)
ARGS=

s07e03: s07e03.c

run: s07e03
	./s07e03 $(ARGS)
ARGS=

s07e06: s07e06.c

run: s07e06
	./s07e06 $(ARGS)
clean:
	rm s07e01 s07e03 s07e06
