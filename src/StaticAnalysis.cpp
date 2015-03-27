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

void StaticAnalysis::Analysis(Symbol* p){
	std::set<std::string> unused;
	getAllSymbols(p);
	
	// for(std::list<Symbol*>::iterator it = listSymbol.begin(); it != listSymbol.end(); ++it){
	// 	std::cout << (*it)->to_string();
	// }
	
	std::list<Symbol*>::iterator it = listSymbol.begin();

	while (it != listSymbol.end()){
		//If symbol is VAR
			//it++
			//while it is not pv
				//New entry in map but linked to nothing
				//Add this var in a set of unused var
				//it++
			//end while

		if(typeid(**it) == typeid(Variable)){
			it++;
			while(typeid(**it) != typeid(ExpPv)){
				if(typeid(**it) == typeid(Id)){
					if(unused.find(((Id*)(*it))->getName()) == unused.end()){
						unused.insert(((Id*)(*it))->getName());
						varValue.insert(std::pair<std::string,Symbol*>(((Id*)(*it))->getName(),NULL));
					}
					else{
						std::cout << "The variable " << ((Id*)(*it))->getName() << " already exists" << std::endl;
					}
				}
				it++;
			}
		}
		//If symbol is CONST
			//it++
			//while it is not pv
				//Get the value of const
				//New entry in map
				//Add this const in a set of unused var
				//it++
			//end while
		else if(typeid(**it) == typeid(Constante)){
			it++;
			while(typeid(**it) != typeid(ExpPv)){
				if(typeid(**it) == typeid(Id)){
					if(unused.find(((Id*)(*it))->getName()) == unused.end()){
						unused.insert(((Id*)(*it))->getName());
						Id* constant = (Id*)(*it);
						it++;
						it++;
						varValue.insert(std::pair<std::string,Symbol*>(constant->getName(),new DConst(SymbolEnum::n, constant->getName(), ((Nombre*)(*it))->getVal())));
					}
					else{
						std::cout << "The constant " << ((Id*)(*it))->getName() << " already exists" << std::endl;
					}
				}
				it++;
			}
		}
		//If symbol is ECRIRE
			//it++
			//while it is not pv
				//See if VAR exists
				//See if VAR has a value
				//See if a VAR is used
					//Remove it from set of unused var
				//it++
			//end while
		else if(typeid(**it) == typeid(W)){
			it++;
			while(typeid(**it) != typeid(ExpPv)){
				if(typeid(**it) == typeid(Id)){
					if(varValue.find(((Id*)(*it))->getName()) == varValue.end()){
						std::cout << "The variable " << ((Id*)(*it))->getName() << " does not exist" << std::endl;
					}else if(varValue.find(((Id*)(*it))->getName())->second == NULL){
						std::cout << "The variable " << ((Id*)(*it))->getName() << " was not assigned" << std::endl;
					}else{
						//Remove it from set of unused var
					}
				}
			}
		}
		else{
			it++;
		}
		//If symbol is LIRE
			//it++
			//while it is not pv
				//See if VAR exists
				//See if it is not followed by a CONST
				//it++
			//end while
			//continue
		//If symbol is id
			//Do the affectation + remove used var if there are some
	}

	/*std::ifstream ifs(fileName);
	std::istringstream iss;
	std::string sub;
	std::string str;
	std::string line;
	if(ifs.is_open()){
		while(getline(ifs,line)){
			//Split line by ' ', ','
			iss.str(line);
			//TODO pas sûr que ça marche
			getline(iss, sub, ' ');
			str = iss.str().substr(iss.str().find_first_of(' '));
			//Enlève tous les espaces restants
			boost::erase_all(str, " ");
			//If line begins by var then create a symbol ...
			if(!sub.compare("var")){
				std::vector<std::string> variables;
				boost::split(variables, str, boost::is_any_of(",;"));
				//Pour chaque valeur dans variables -> faire le symbole associé
				for(int i = 0; i<variables.size()-1; i++){
					std::cout << "variable(i) \"" << variables.at(i) << "\""<< std::endl;
					if(varValue.find(variables.at(i)) == varValue.end()){
						varValue.insert(std::pair<std::string,Symbol*>(variables.at(i),NULL));
					}
					else{
						std::cout << "The variable " << variables.at(i) << " was already declared" << std::endl;
					}
				}
			}
			//If line begins by const then create a symbol ...
			else if(!sub.compare("const")){
				std::vector<std::string> constants, aConstant;
				boost::split(constants, str, boost::is_any_of(",;"));
				for(int i = 0; i < constants.size()-1; i++){
					boost::split(aConstant, constants.at(i), boost::is_any_of("="));
					if(varValue.find(aConstant.at(0)) == varValue.end()){
						varValue.insert(std::pair<std::string,Symbol*>(aConstant.at(0), new DConst(SymbolEnum::n, aConstant.at(0), atoi(aConstant.at(1).c_str()))));	//TODO : id mis à l'arrache
					}
					else{
						std::cout << "The constant " << aConstant.at(0) << " was already declared" << std::endl;
					}
				}
			}
			//If line begins by ecrire then see if in the next split there are some var or const that don't exist, that are not initialized
			else if(!sub.compare("ecrire")){
				//TODO à tester
				std::vector<std::string> variables;
				boost::match_results<std::string::const_iterator> results;	

				boost::split(variables, str, boost::is_any_of("+/-*();"));
				for(int i = 0; i < variables.size()-1; i++){
					//See if it's a variable or a number
					//If it's a variable
					if(!boost::regex_match(variables.at(i), results, boost::regex("^[0-9]+"))){		//TODO : Pas sûr que ça fasse ce qu'il faut
						//If it doesn't exist
						if(varValue.find(variables.at(i)) == varValue.end()){
							std::cout << "The variable " << variables.at(i) << " does not exist" << std::endl;
						}
						//If it was not assigned
						else if(varValue.find(variables.at(i))->second == NULL){
							std::cout << "The variable " << variables.at(i) << " was not assigned" << std::endl;
						}
					}				
				}
			}
			//If line begins by lire then see if it isn't followed by a const
			else if(!sub.compare("lire")){
				//TODO Virer la 
				boost::match_results<std::string::const_iterator> results;
				std::map<std::string, Symbol*>::iterator found;
				if(boost::regex_match(str, results, boost::regex("[0-9]+"))){
					cout << str << " is not a variable" << std::endl;
					continue;
				}
				boost::erase_all(str, ";");
				found = varValue.find(str);
				//If it's a constant
				if (typeid(found->second).name() == "DConst"){
					std::cout << str << " is a constant" << std::endl;
				}
				//If it's a variable which was never assigned
				else if(varValue.find(str)->second == NULL){
					varValue.find(str)->second = new DVar(SymbolEnum::n, str, 0);
				}
			}
			else if(varValue.find(sub) != varValue.end()){
				if(varValue.find(sub)->second == NULL){
					varValue.find(sub)->second = new DVar(SymbolEnum::n, sub, 0);	//TODO Valeur mise random
				}
				else if(typeid(varValue.find(sub)->second).name() == "DConst"){
					std::cout << "You can't assigned a value to the constant " << sub << std::endl;
				}
			}
		}*/
		//Go through the Symbol table and see if there are some var that were not used
		// for(std::map<std::string, Symbol*>::iterator it = varValue.begin(); it != varValue.end(); it++){
		// 	if(it->second == NULL){
		// 		std::cout << "The variable " << it->first << " was declared but never assigned" << std::endl;
		// 	}
		// }
	/*}
	else{
		std::cout<< "Unable to open the file" <<std::endl;
	}*/
}

StaticAnalysis::~StaticAnalysis(){
	//TODO

}

/*int main(void){
	StaticAnalysis sa("test.lt");
	sa.Analysis();

}*/