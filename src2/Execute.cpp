#include "Execute.h"

Execute::Execute(Symbol * p)
{
	this->top = p;
}	

std::map<std::string, int> Execute::exec_variables;
std::map<std::string, const int> Execute::exec_const;

void Execute::run()	
{
	list<Symbol*> listSymbol = this->top->getListSymbol();
	list<Symbol*>::iterator ite;
	for(ite = listSymbol.begin() ; ite != listSymbol.end() ; ++ite)
	{
		(*ite)->execute();
	}
}