#makefile rudimentaire

.PHONY: clean
.SUFFIXES:

sourcefiles = main.cpp Etats.cpp Automate.cpp
progname= Analyseur.prout
CC=g++
CFLAGS= -std=c++11 -lboost_regex
# quand on veut voir les warnings -Wall -Wextra -pedantic 

all: $(sourcefiles) clean
	$(CC) $(CFLAGS) -o $(progname) $(sourcefiles)
	cp $(progname) ../bin/$(progname)

clean:
	$(RM) $(progname)
	$(RM) ../bin/$(progname)
