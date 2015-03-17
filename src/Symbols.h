#ifndef SYMBOLS_H
#define SYMBOLS_H

#include "Symbol.h"

/* D
	P
	Instr */

class D:public Symbol{
public:
	D(int id) : Symbol(id){}
	~D() {}

};

class P:public Symbol{
public:
	P(int id) : Symbol(id){}
	~P() {}
};

class I:public Symbol{
public:
	I(int id) : Symbol(id){}
	~I() {}
};


#endif
