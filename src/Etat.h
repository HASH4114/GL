#include <iostream>
#include "Automate.h"
#include "Symbole.h"

using namespace std;

class Etat {

public:
	Etat(string name);
	virtual ~Etat();
	void print() const;
	virtual bool transition(Automate  &automate, Symbole *s) = 0;
protected:
	string name;

};

