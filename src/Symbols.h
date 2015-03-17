#ifndef SYMBOLS_H
#define SYMBOLS_H


#include <string>
#include "Symbol.h"

using namespace std; 
/* D
	P
	Instr
	*/

class D:public Symbol{
public:
	D(int id);
	virtual ~D() {}

};

class Ld:public Symbol{
public:
	Ld(int id);
	virtual ~Ld(){}
private:
	list<D> ld; //method for add an element to the list
};

class I:public Symbol{
public:
	I(int id);
	virtual ~I() {}
};

class Li:public Symbol{
public:
	Li(int id); //method for add an element to the list
	virtual ~Li() {}
private:
	list<I> li;
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

class Expplus:public ExpBinaire{
public:
	Expplus(int id);
	virtual ~Expplus(){}
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
	DVar(int id);
	void read(); 
	void write();
	virtual ~DVar() {}
private:
	string name;
	double value;
};

class DConst:public D{
public:
	DConst(int id);
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
