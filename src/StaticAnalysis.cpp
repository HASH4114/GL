#include "StaticAnalysis.h"

StaticAnalysis::StaticAnalysis(){}

void StaticAnalysis::getAllSymbols(Symbol* p){
	std::list<Symbol*> symbolList = p->getListSymbol();
	std::list<Symbol*>::iterator it;
	for(std::list<Symbol*>::iterator it = symbolList.begin(); it != symbolList.end(); ++it){
		if((*it)->getListSymbol().empty()){
			listSymbol.push_back((*it));
		}
		else{
			getAllSymbols(*it);
		}
	}
}

bool StaticAnalysis::Analysis(Symbol* p){
	std::set<std::string> unused;
	bool status = true;
	getAllSymbols(p);

	std::list<Symbol*>::iterator it = listSymbol.begin();
	while (it != listSymbol.end()){
		//If symbol is VAR
		if(typeid(**it) == typeid(Variable)){
			it++;
			//Until we find a semicolon
			while(typeid(**it) != typeid(ExpPv)){
				if(typeid(**it) == typeid(Id)){
					//If the variable doesn't exist yet
					if(unused.find(((Id*)(*it))->getName()) == unused.end()){
						unused.insert(((Id*)(*it))->getName());
						varValue.insert(std::pair<std::string,Symbol*>(((Id*)(*it))->getName(),NULL));
					}
					else{
						std::cerr << "la variable " << ((Id*)(*it))->getName() << " est deja declaree" << std::endl;
					}
				}
				it++;
			}
		}
		//If symbol is CONST
		else if(typeid(**it) == typeid(Constante)){
			it++;
			while(typeid(**it) != typeid(ExpPv)){
				if(typeid(**it) == typeid(Id)){
					//If the constant doesn't exist yet
					if(unused.find(((Id*)(*it))->getName()) == unused.end()){
						unused.insert(((Id*)(*it))->getName());
						Id* constant = (Id*)(*it);
						std::advance(it, 2);
						varValue.insert(std::pair<std::string,Symbol*>(constant->getName(),new DConst(SymbolEnum::n, constant->getName(), ((Nombre*)(*it))->getVal())));
					}
					else{
						std::cerr << "la constante " << ((Id*)(*it))->getName() << " est deja declaree" << std::endl;
					}
				}
				it++;
			}
		}
		//If symbol is ECRIRE
		else if(typeid(**it) == typeid(W)){
			bool writen = false;
			it++;
			std::list<Symbol*>::iterator ite = it;
			while(typeid(**it) != typeid(ExpPv)){
				if(typeid(**it) == typeid(Id)){
					std::map<std::string, Symbol*>::iterator found = varValue.find(((Id*)(*it))->getName());
					//If the variable doesn't exist or isn't initialized and the message wasn't already written
					if((found == varValue.end() || found->second == NULL) && !writen){
						std::string sortie = varUnknown(ite);
						std::cerr << sortie << std::endl;
						writen = true;
						status = false;
					}else{
						unused.erase(((Id*)(*it))->getName());
					}
				}
				it++;
			}
		}
		//If symbol is LIRE
		else if(typeid(**it) == typeid(R)){
			it++;
			while(typeid(**it) != typeid(ExpPv)){
				if(typeid(**it) == typeid(Id)){
					std::map<std::string, Symbol*>::iterator found = varValue.find(((Id*)(*it))->getName());
					if(found == varValue.end()){
						std::cerr << "la variable " << ((Id*)(*it))->getName() << " n'a pas ete declaree." << std::endl;
						status = false;
					}
					else if(found->second == NULL){
						found->second = new DVar(SymbolEnum::n, ((Id*)(*it))->getName(), 0);
					}
					else if(typeid(found->second) == typeid(DConst)){
						std::cerr << ((Id*)(*it))->getName() << " est une constante." << std::endl;
						status = false;
					}
				}
				it++;
			}
		}
		//If symbol is id
			//Do the affectation + remove used var if there are some
		else if(typeid(**it) == typeid(Id)){
			bool writen = false;
			std::map<std::string, Symbol*>::iterator affected = varValue.find(((Id*)(*it))->getName());
			std::map<std::string, Symbol*>::iterator found;
			if(affected == varValue.end()){
				std::cerr << "la variable " << ((Id*)(*it))->getName() << " n'a pas ete declaree." << std::endl;
				status = false;
			}
			else if(typeid(affected->second) == typeid(DConst)){
				std::cerr << ((Id*)(*it))->getName() << " est une constante." << std::endl;
				status = false;
			}
			else if(affected->second == NULL){
				affected->second = new DVar(SymbolEnum::n, ((Id*)(*it))->getName(), 0);
			}
			it++;
			std::list<Symbol*>::iterator beginingAff = it;
			beginingAff++;
			while(typeid(**it) != typeid(ExpPv)){
				if(typeid(**it) == typeid(Id)){
					found = varValue.find(((Id*)(*it))->getName());
					if((found->second == NULL || found == varValue.end())&& !writen){
						std::string sortie = varUnknown(beginingAff);
						std::cerr << sortie << std::endl;
						writen = true;
						status = false;
					}
					else{
						unused.erase(((Id*)(*it))->getName());
					}
				}
				it++;
			}
		}
		else{
			it++;
		}
	}
	bool shown = false;
	for(std::map<std::string, Symbol*>::iterator ite = varValue.begin(); ite != varValue.end(); ite++){
		if(ite->second == NULL){
			std::cerr << "variable non affectee : " << ite->first << std::endl;
		}
	}
	for(std::set<string>::iterator ite = unused.begin(); ite != unused.end(); ite++){
		std::cerr << "variable non utilisee : " << *ite << std::endl;
	}
	return status;
}

StaticAnalysis::~StaticAnalysis(){
	for(std::map<std::string, Symbol*>::iterator it = varValue.begin(); it != varValue.end(); it++){
		if(it->second != NULL){
			delete it->second;
		}
	}
}

std::string StaticAnalysis::varUnknown(std::list<Symbol*>::iterator begining){
	std::string sortie = "une valeur dans l'expression ";
	while (typeid(**begining) != typeid(ExpPv)){
		sortie += (*begining)->to_string();
		begining++;
	}
	sortie += " n'est pas connue.";
	return sortie;
}

/*void StaticAnalysis::propagation(Symbol* p)
{
	list<Symbol*> listSymbol = p->getListSymbol();
	list<Symbol*>::iterator ite;
	for (ite = listSymbol.begin(); ite != listSymbol.end(); ++ite)
	{
		Id* c1 = dynamic_cast<Id*>(*ite);
		list<Symbol*> l = (*ite)->getListSymbol();
		//If the symbol is composed by other symbols
		if (!(l.empty()))
		{

			//If the symbol is an expression
			if ((**ite) == Ee)
			{
				if ((*ite)->getListSymbol().size() == 3)
				{
					//Stocking the 3 symbols
					Symbol* s1;
					Symbol* s2;
					Symbol* s3;

					s1 = l.front();
					l.pop_front();
					s2 = l.front();
					l.pop_front();
					s3 = l.front();
					l.pop_front();

					//We get pointers on the ids that are supposed to be const or var
					//If it's not a const or var, the null test will fail.
					Id* s1i=nullptr;
					Id* s3i=nullptr;
					if(s1->getListSymbol().size()==1)
					{s1i = dynamic_cast<Id*>(s1->getListSymbol().front());}
					if(s3->getListSymbol().size()==1)
					{s3i = dynamic_cast<Id*>(s3->getListSymbol().front());}

				}
			}
		}
		//If the type of the element is an Id
		else if ((*ite)->getId()==0)
		{
				//Checking if it is a const
				std::map<std::string, Symbol*>::iterator affected = varValue.find(c1->getName());
				//If it is found it's a const, else it's a variable
				if(!(affected == varValue.end()))
				{
					Nombre* nb = new Nombre(n);
					nb->setVal(affected->second.getValue());
					*ite = nb;
				}
		}
	}
}
*/
