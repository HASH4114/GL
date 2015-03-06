#ifndef ETAT_H
#define ETAT_H

#include <iostream>
#include <string>
#include "Symbol.h"
#include "Automate.h"

using namespace std;

class Etat {

public:
	Etat(string name);
	virtual ~Etat();
	void print() const;
	virtual bool transition(Automate  &automate, Symbol *s) = 0;
protected:
	string name;

};

#endif
