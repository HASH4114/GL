#ifndef SYMBOL_H
#define SYMBOL_H

#include <list>
#include <string>


class Symbol {
	protected:
		int ident;
	private:
		std::list<Symbol*> listSymbol;
	public:
		void addSymbolToList(Symbol* s){listSymbol.push_back(s);}
		std::list<Symbol*> getListSymbol(){return listSymbol;}
		Symbol(int id) : ident(id) {}
		virtual ~Symbol(){}
		virtual std::string to_string(){return "";}
		int getId(){return ident;}
		void print();
		//Redefinition of the operator that is supposed to convert Symbol in int.
		//Doesn't work for now, that's apparently why we have an error.
		operator int() const {return ident;}
};

#endif
