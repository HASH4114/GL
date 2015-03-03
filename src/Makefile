#makefile rudimentaire

.PHONY: clean
.SUFFIXES:

sourcefiles = main.cpp
progname= LG
CC=g++
CFLAGS= -std=c++11 -Wall -Wextra -pedantic

all: $(sourcefiles) clean
	$(CC) $(CFLAGS) -o $(progname) $(sourcefiles)
	cp $(progname) ../bin/$(progname)

clean:
	$(RM) $(progname)
	$(RM) ../bin/$(progname)

