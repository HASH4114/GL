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
		void setListSymbol(std::list<Symbol*> aList){listSymbol = aList;}
		Symbol(int id) : ident(id) {}
		virtual ~Symbol(){}
		virtual std::string to_string(){return "";}
		virtual void execute(){}
		virtual void execute(std::string, int){}
		int getId(){return ident;}
		void print();
		operator int() const {return ident;}
};

#endif
