#include "Etats.h"


Automate::Automate(){
  stateStack.push(new E0());
}

//Method that allows a shift of the symbol and that stocks the state and symbol into the stack
void Automate::shift(Symbol* s, Etat *e)
{
  stateStack.push(e);
  symbolStack.push(s);
}

void Automate::reduce(Symbol* s, int nbStatesToPop)
{
    for (int i = 0; i<nbStatesToPop; i++)
    {
        stateStack.pop();
    }
    stateStack.top()->transition(this, s);
}

Etat* Automate::getStateStackTop(){
  return stateStack.top();
}

void Automate::accept()
{
}

Symbol* Automate::popS()
{
  Symbol* symbol = symbolStack.top();
  symbolStack.pop();
  return symbol;
}
