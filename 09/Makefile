CC=gcc
CFLAGS=-Wall -Werror -Wextra -Wpedantic -std=c18

.PHONY: all clean

all: s09e02 s09e02_D s09e02_D3 s09e03 s09e04 s09e05 s09e05.so
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c18

s09e02: s09e02.c

s09e02_D: CFLAGS += -D DEBUG
s09e02_D: s09e02.c
	$(CC) $(CFLAGS) $^ -o $@

s09e02_D3: CFLAGS += -D DEBUG=3
s09e02_D3: s09e02.c
	$(CC) $(CFLAGS) $^ -o $@

run: s09e02
	./s09e02 $(ARGS)
ARGS=

s09e03: s09e03.c

run: s09e03
	./s09e03 $(ARGS)
ARGS=

s09e04: s09e04.c

run: s09e04
	./s09e04 $(ARGS)
ARGS=

s09e05: s09e05.c uint_list.c uint_list_util.c

s09e05.so: s09e05.c
	$(CC) -fPIC -shared s09e05.c uint_list.c uint_list_util.c -o $@ $(CFLAGS)

run: s09e05
	./s09e05 $(ARGS)
clean:
	rm s09e02 s09e02_D s09e02_D3 s09e03 s09e04 s09e05 s09e05.so
