#include "Symbols.h"

void Ld::addDeclaration(D* d){
	this->ld.push_back(d);
}

void Li::addInstruction(I* i){
	this->li.push_back(i);
}

void Lid::addIdentifier(I* i){
	this->lid.push_back(i);
}

void Lcst::addConstant(I* i){
	this->lcst.push_back(i);
}
