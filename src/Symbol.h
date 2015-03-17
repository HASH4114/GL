#ifndef SYMBOL_H
#define SYMBOL_H

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

enum SymbolEnum {id,add,ss,mul,dv,pl,pr,r,w,v,c,vi,pv,e,n,af,$,Ppe,Pe,Ld,Lie,De,Ie,Ee,Lcste,Lide};

class Symbol {
	protected:
		int ident;
	public:
		Symbol(int id) : ident(id) {}
		virtual ~Symbol(){}
		void print();
		//Redefinition of the operator that is supposed to convert Symbol in int.
		//Doesn't work for now, that's apparently why we have an error. 
		operator int() const {return ident;}
};

#endif
