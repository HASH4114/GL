#include "Automate.h"
#include "Etat.h"

//Method that allows a shift of the symbol and that stocks the state and symbol into the stack
void Automate::shift(Symbol s, Etat *e){
  stateStack.push(e);
  symbolStack.push(s);
}

void Automate::reduce(Symbol s, Etat *e){
}

void Automate::accept(Symbol s, Etat *e){
}
