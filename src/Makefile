#makefile rudimentaire

.PHONY: clean
.SUFFIXES:

sourcefiles = Regex.cpp Parseur.cpp
progname= Analyseur
CC=g++
CFLAGS= -std=c++11
LIBS= -lboost_regex -lboost_program_options
INC_PATH=-I/usr/local/include

# quand on veut voir les warnings -Wall -Wextra -pedantic

all: $(sourcefiles) clean
	$(CC) $(CFLAGS) $(INC_PATH) -o $(progname) $(sourcefiles) $(LIBS)
	cp $(progname) ../bin/$(progname)

clean:
	$(RM) $(progname)
	$(RM) ../bin/$(progname)
