#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "Symbols.h"
#include <stack>

class Etat;

class Automate{

	public:
		Automate();
		virtual ~Automate();
		void shift(Symbol s, Etat *e);
		//If we don't use a pointer, it has no choice but to be an object of the class
		//Etat, and Etat is abstract.
		void reduce(Symbol s, int nbStatesToPop);
		void accept();
		Symbol popS();
	private:
		stack <Etat*> stateStack;
		stack <Symbol> symbolStack;

};

#endif
