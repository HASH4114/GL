#ifndef SYMBOL_H
#define SYMBOL_H

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
