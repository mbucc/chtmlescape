# Run unit tests
# @Sun Aug  3 20:13:02 EDT 2014
# @author Mark Bucciarelli <mkbucc@gmail.com>

T=deps/tap.c

CC=gcc
CFLAGS=-Wall -I./deps/tap.c

all: test

test: dep test.c ${T}/tap.c ../htmlescape.h ../htmlescape.c
	$(CC) $(CFLAGS) -o test test.c ${T}/tap.c ../htmlescape.c
	./test

dep: ${T}

${T}:
	clib install thlorenz/tap.c

clean:
	rm -f test