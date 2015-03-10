#makefile rudimentaire

.PHONY: clean
.SUFFIXES:

sourcefiles = Regex.cpp
progname= Analyseur.prout
CC=g++
CFLAGS= -std=c++11 -Wall -Wextra -pedantic -lboost_regex

all: $(sourcefiles) clean
	$(CC) $(CFLAGS) -o $(progname) $(sourcefiles)
	cp $(progname) ../bin/$(progname)

clean:
	$(RM) $(progname)
	$(RM) ../bin/$(progname)
