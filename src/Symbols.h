#ifndef SYMBOLS_H
#define SYMBOLS_H


#include <string>
#include <boost/lexical_cast.hpp>

#include "Symbol.h"

using namespace std;

/*
		Explanation of the enum
	0 id 	: name of the variable
	1 add : replace +
	2 ss 	: replace -
	3 mul	: replace *
	4 dv	: replace /
	5 pl 	: replace (
	6 pr  : replace )
	7 r 	: stands for read
	8 w 	: stands for write
	9 v 	: stands for var
	10 c 	: stands for const
	11 vi 	: replace the ,
	12 pv	: replace ;
	13 e 	: replace =
	14 n 	: value of the variable or the constant
	15 af	: replace :=
	16 $	: the end.
	17 Ppe	: P'
	18 Pe 	: the program
	19 Lde	: List of declarations
	20 Lie	: List of instructions
	21 De 	: A declaration
	22 Ie 	: An instruction
	23 Ee 	: An expression
	24 Lcste: List of constants delarations
	25 Lide: List of id
*/

enum SymbolEnum {id,add,ss,mul,dv,pl,pr,r,w,v,c,vi,pv,e,n,af,dol,Ppe,Pe,Lde,Lie,De,Ie,Ee,Lcste,Lide};

class D:public Symbol{
public:
	D(int id):Symbol(id){}
	string to_string(){return "";}
	virtual ~D() {}
};

class Ld:public Symbol{
public:
	Ld(int id):Symbol(id){}
	string to_string(){return "";}
	virtual ~Ld(){}
};

class I:public Symbol{
public:
	I(int id):Symbol(id){}
	string to_string(){return "";}
	virtual ~I() {}

};

class Li:public Symbol{
public:
	Li(int id):Symbol(id){}
	string to_string(){return "";}
	virtual ~Li() {}
};

class Lid:public Symbol{
public:
	Lid(int id):Symbol(id){}
	string to_string(){return "";}
	virtual ~Lid() {}
};


class Lcst:public Symbol{
public:
	Lcst(int id):Symbol(id){} //method for add an element to the list
	string to_string(){return "";}
	virtual ~Lcst() {}
};


class P:public Symbol{
public:
	P(int id):Symbol(id){}
	string to_string(){return "";}
	virtual ~P() {}
};

class Exp:public Symbol{
public:
	Exp(int id):Symbol(id){}
	string to_string(){return "";}
	double eval(Exp Exp);
	virtual ~Exp(){}
};



class ExpUnaire:public Exp{
public:
	ExpUnaire(int id):Exp(id){}
	string to_string(){return "";}
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
	string to_string(){return "";}
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
	string to_string(){return "lire ";}
	virtual ~R() {}
private:
	//Variable var;
};

class W:public I{
public:
	W(int id):I(id){}
	string to_string(){return "ecrire ";}
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

//execution et analyse statique
class DVar:public D{
public:
	DVar(int id):D(id){}
	DVar(int id,string name, int val) : D(id),name(name),value(val){}
	string to_string(){return "";}
	void read();
	void write();
	virtual ~DVar() {}
private:
	string name;
	int value;
};
//execution et analyse statique
class DConst:public D{
public:
	DConst(int id):D(id){}
	DConst(int id,string name,int val): D(id),name(name),value(val) {}
	string to_string(){return "";}
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
	string to_string(){return boost::lexical_cast<string>(val);}
	int getVal(){return val;}
	virtual ~Nombre(){}
private:
	int val;
};


#endif
