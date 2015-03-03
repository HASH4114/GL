#makefile rudimentaire

.PHONY: clean
.SUFFIXES:

sourcefiles = reg_ex.cpp
progname= GL
CC=g++
CFLAGS= -std=c++11 -Wall -Wextra -pedantic -lboost_regex

all: $(sourcefiles) clean
	$(CC) $(CFLAGS) -o $(progname) $(sourcefiles)
	cp $(progname) ../bin/$(progname)

clean:
	$(RM) $(progname)
	$(RM) ../bin/$(progname)

