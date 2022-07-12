.PHONY:clean install distclean

INCLUDE_PATH=../include
CC=gcc
CFLAGS=-I$(INCLUDE_PATH) -Wall -c -g
CPPFLAGS=
LDFLAGS=-lpthread
LIBRARY_PATH=../library
TARGET=PTHREAD_COPY
RM=sudo rm -rf
CP=sudo cp
SFILE=$(wildcard *.c)
DFILE=$(patsubst %.c,%.o,$(SFILE))


$(TARGET):$(DFILE)
	$(CC) $^ -lpthread -o $@

%.o:%.c
	$(CC) $(CFLAGS) $<

clean:
	$(RM) $(DFILE) $(TARGET)

distclean:

install:
