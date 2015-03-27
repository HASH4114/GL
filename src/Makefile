#makefile rudimentaire

.PHONY: clean
.SUFFIXES:


sourcefiles = main.cpp Etats.cpp Automate.cpp Symbols.cpp Parseur.cpp Regex.cpp StaticAnalysis.cpp
progname= lut
CC=g++
CFLAGS=-g -std=c++11 
LIBS= -lboost_regex -lboost_program_options
INC_PATH=-I/usr/local/include

# quand on veut voir les warnings -Wall -Wextra -pedantic

all: $(sourcefiles) clean
	$(CC) $(CFLAGS) $(INC_PATH) -o $(progname) $(sourcefiles) $(LIBS)
	cp $(progname) ../$(progname)

clean:
	$(RM) $(progname)
	$(RM) ../bin/$(progname)
