#include "Automate.h"
#include "Etat.h"

//Method that allows a shift of the symbol and that stocks the state and symbol into the stack
void Automate::shift(Symbol s, Etat *e){
	symbolStack.push(s);
	stateStack.push(e);
}