#ifndef SYMBOLS_H
#define SYMBOLS_H


#include <string>
#include "Symbol.h"

using namespace std;

/*
		Explanation of the enum
	id 	: name of the variable
	add : replace +
	ss 	: replace -
	mul	: replace *
	dv	: replace /
	pl 	: replace (
	pr  : replace )
	r 	: stands for read
	w 	: stands for write
	v 	: stands for var
	c 	: stands for const
	vi 	: replace the ,
	pv	: replace ;
	e 	: replace =
	n 	: value of the variable or the constant
	af	: replace :=
	$	: the end.
	Ppe	: P'
	Pe 	: the program
	Lde	: List of declarations
	Lie	: List of instructions
	De 	: A declaration
	Ie 	: An instruction
	Ee 	: An expression
	Lcste: List of constants delarations
	Lide: List of id
*/

enum SymbolEnum {id,add,ss,mul,dv,pl,pr,r,w,v,c,vi,pv,e,n,af,dol,Ppe,Pe,Lde,Lie,De,Ie,Ee,Lcste,Lide};

class D:public Symbol{
public:
	D(int id):Symbol(id){}
	virtual ~D() {}
};

class Ld:public Symbol{
public:
	Ld(int id):Symbol(id){}
	virtual ~Ld(){}
};

class I:public Symbol{
public:
	I(int id):Symbol(id){}
	virtual ~I() {}

};

class Li:public Symbol{
public:
	Li(int id):Symbol(id){}
	virtual ~Li() {}
};

class Lid:public Symbol{
public:
	Lid(int id):Symbol(id){}
	virtual ~Lid() {}
};


class Lcst:public Symbol{
public:
	Lcst(int id):Symbol(id){} //method for add an element to the list
	virtual ~Lcst() {}
};


class P:public Symbol{
public:
	P(int id):Symbol(id){}
	virtual ~P() {}
};

class Exp:public Symbol{
public:
	Exp(int id):Symbol(id){}
	double eval(Exp Exp);
	virtual ~Exp(){}
};



class ExpUnaire:public Exp{
public:
	ExpUnaire(int id):Exp(id){}
	virtual ~ExpUnaire(){}
};

class ExpParD:public ExpUnaire{
public:
	ExpParD(int id):ExpUnaire(id){}
	string to_string(){return ")";}
	virtual ~ExpParD(){}
};

class ExpParG:public ExpUnaire{
public:
	ExpParG(int id):ExpUnaire(id){}
	string to_string(){return "(";}
	virtual ~ExpParG(){}
};

class ExpEg:public ExpUnaire{
public:
	ExpEg(int id):ExpUnaire(id){}
	string to_string(){return "=";}
	virtual ~ExpEg(){}
};

class ExpVir:public ExpUnaire{
public:
	ExpVir(int id):ExpUnaire(id){}
	string to_string(){return ",";}
	virtual ~ExpVir(){}
};

class ExpPv:public ExpUnaire{
public:
	ExpPv(int id):ExpUnaire(id){}
	string to_string(){return "; \n";}
	virtual ~ExpPv(){}
};

class ExpBinaire:public Exp{
public:
	ExpBinaire(int id):Exp(id){}
	virtual ~ExpBinaire(){}
};

class ExpMult:public ExpBinaire{
public:
	ExpMult(int id):ExpBinaire(id){}
	string to_string(){return "*";}
	virtual ~ExpMult(){}
};

class ExpPlus:public ExpBinaire{
public:
	ExpPlus(int id):ExpBinaire(id){}
	string to_string(){return "+";}
	virtual ~ExpPlus(){}
};

class ExpDiv:public ExpBinaire{
public:
	ExpDiv(int id):ExpBinaire(id){}
	string to_string(){return "/";}
	virtual ~ExpDiv(){}
};

class ExpMoins:public ExpBinaire{
public:
	ExpMoins(int id):ExpBinaire(id){}
	string to_string(){return "-";}
	virtual ~ExpMoins(){}
};

class R:public I{
public:
	R(int id):I(id){}
	string to_string(){return "Lire ";}
	virtual ~R() {}
private:
	//Variable var;
};

class W:public I{
public:
	W(int id):I(id){}
	string to_string(){return "Ecrire ";}
	virtual ~W() {}
private:
	//Variable var;
	//Constante cons;
};

class Aff:public I{
public:
	Aff(int id):I(id){}
	string to_string(){return ":=";}
	virtual ~Aff() {}
private:
	//Variable var;
};


//Retravailler


class DVar:public D{
public:
	DVar(int id):D(id){}
	DVar(int id,string name, int val) : D(id),name(name),value(val){}
	void read();
	void write();
	virtual ~DVar() {}
private:
	string name;
	int value;
};

class DConst:public D{
public:
	DConst(int id):D(id){}
	DConst(int id,string name,int val): D(id),name(name),value(val) {}
	void read();
	virtual ~DConst() {}
private:
	string name;
	int value;
};

//var
class Variable:public Exp{
public:
	Variable(int id):Exp(id){}
	string to_string(){return "var ";}
	virtual ~Variable(){}
};
//const
class Constante:public Exp{
public:
	Constante(int id):Exp(id){}
	string to_string(){return "const ";}
	virtual ~Constante(){}
};
//id
class Id:public Symbol{
public:
	Id(int id): Symbol(id){}
	Id(int id,string name): Symbol(id),name(name){}
	string to_string(){return name;}
	string getName(){return name;}
	virtual ~Id(){}
private:
	string name;
};
//nb
class Nombre:public Exp{
public:
	Nombre(int id):Exp(id){}
	Nombre(int id,int val):Exp(id),val(val){}
	string to_string(){return ""+val;}
	int getVal(){return val;}
	virtual ~Nombre(){}
private:
	int val;
};


#endif
