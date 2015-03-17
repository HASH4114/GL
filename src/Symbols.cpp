#include "Symbols.h"

void Ld::addDeclaration(D* d){
	this->ld.push_back(d);
}

void Li::addInstruction(I* i){
	this->li.push_back(i);
}

