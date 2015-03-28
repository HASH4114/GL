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
			while(typeid(**it) != typeid(ExpPv)){
				if(typeid(**it) == typeid(Id)){
					if(unused.find(((Id*)(*it))->getName()) == unused.end()){
						unused.insert(((Id*)(*it))->getName());
						varValue.insert(std::pair<std::string,Symbol*>(((Id*)(*it))->getName(),NULL));
					}
					else{
						std::cerr << "la variable " << ((Id*)(*it))->getName() << " existe deja." << std::endl;
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
					if(unused.find(((Id*)(*it))->getName()) == unused.end()){
						unused.insert(((Id*)(*it))->getName());
						Id* constant = (Id*)(*it);
						it++;	//TODO Sale
						it++;
						varValue.insert(std::pair<std::string,Symbol*>(constant->getName(),new DConst(SymbolEnum::n, constant->getName(), ((Nombre*)(*it))->getVal())));
					}
					else{
						std::cerr << "la constante " << ((Id*)(*it))->getName() << " existe deja." << std::endl;
					}
				}
				it++;
			}
		}
		//If symbol is ECRIRE
		else if(typeid(**it) == typeid(W)){
			it++;
			while(typeid(**it) != typeid(ExpPv)){
				if(typeid(**it) == typeid(Id)){
					std::map<std::string, Symbol*>::iterator found = varValue.find(((Id*)(*it))->getName());
					if(found == varValue.end()){
						std::cerr << "la variable " << ((Id*)(*it))->getName() << " n'a pas ete declaree." << std::endl;
						status = false;
					}else if(found->second == NULL){
						std::cerr << "la variable " << ((Id*)(*it))->getName() << " n'a pas ete assignee." << std::endl;
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
			while(typeid(**it) != typeid(ExpPv)){
				if(typeid(**it) == typeid(Id)){
					found = varValue.find(((Id*)(*it))->getName());
					if(found->second == NULL){
						std::cerr << ((Id*)(*it))->getName() << " n'a pas ete declaree." << std::endl;
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
