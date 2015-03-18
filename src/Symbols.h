#ifndef SYMBOLS_H
#define SYMBOLS_H


#include <string>
#include "Symbol.h"

using namespace std;

class D:public Symbol{
public:
	D(int id);
	virtual ~D() {}
};

class Ld:public Symbol{
public:
	Ld(int id);
	void addDeclaration(D* d);
	virtual ~Ld(){}
private:
	list<D*> ld; //method for add an element to the list
};

class I:public Symbol{
public:
	I(int id);
	virtual ~I() {}

};

class Li:public Symbol{
public:
	Li(int id); //method for add an element to the list
	void addInstruction(I* i);
	virtual ~Li() {}
private:
	list<I*> li;
};

// Bastien : J'ai créé cette classe parce que j'en ai besoin en fait.
class Lid:public Symbol{
public:
	Lid(int id); //method for add an element to the list
	void addIdentifier(I* i); //TODO : changer en identifiant dans la parenthèse... et dans le cpp aussi
	virtual ~Lid() {}
private:
	list<I*> lid; //TODO : pareil ici..
};

// Bastien : J'ai créé cette classe parce que j'en ai besoin en fait.
class Lcst:public Symbol{
public:
	Lcst(int id); //method for add an element to the list
	void addConstant(I* i); //TODO : changer en constante dans la parenthèse.. et dans le cpp aussi
	virtual ~Lcst() {}
private:
	list<I*> lcst; //TODO : pareil ici..
};


class P:public Symbol{
public:
	P(int id);
	virtual ~P() {}
};

class Exp:public Symbol{
public:
	Exp(int id);
	double eval(Exp Exp);
	virtual ~Exp(){}
};

class Variable:public Exp{
public:
	Variable(int id);
	virtual ~Variable(){}
};

class Constante:public Exp{
public:
	Constante(int id);
	virtual ~Constante(){}
};

class Nombre:public Exp{
public:
	Nombre(int id);
	virtual ~Nombre(){}
};

class ExpUnaire:public Exp{
public:
	ExpUnaire(int id);
	virtual ~ExpUnaire(){}
};

class ExpBinaire:public Exp{
public:
	ExpBinaire(int id);
	virtual ~ExpBinaire(){}
};

class ExpMult:public ExpBinaire{
public:
	ExpMult(int id);
	virtual ~ExpMult(){}
};

class ExpPlus:public ExpBinaire{
public:
	ExpPlus(int id);
	virtual ~ExpPlus(){}
};

class ExpDiv:public ExpBinaire{
public:
	ExpDiv(int id);
	virtual ~ExpDiv(){}
};

class ExpMoins:public ExpBinaire{
public:
	ExpMoins(int id);
	virtual ~ExpMoins(){}
};

class DVar:public D{
public:
	DVar(int id,string name, double val) : D(id),name(name),value(val){}
	void read();
	void write();
	virtual ~DVar() {}
private:
	string name;
	double value;
};

class DConst:public D{
public:

	DConst(int id,string name,double val): D(id),name(name),value(val) {}
	void read();
	virtual ~DConst() {}
private:
	string name;
	const double value;
};

class R:public I{
public:
	R(int id);
	virtual ~R() {}
private:
	Variable var;
};

class W:public I{
public:
	W(int id);
	virtual ~W() {}
private:
	Variable var;
	Constante cons;
};

class Aff:public I{
public:
	Aff(int id);
	virtual ~Aff() {}
private:
	Variable var;
};





#endif
