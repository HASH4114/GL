#include "Symbols.h"

void Ld::execute() {
	// std::cout << "Execute Ld" << std::endl; 
	list<Symbol*> listSymbol = this->getListSymbol();
    list<Symbol*>::iterator ite;
    for(ite = listSymbol.begin() ; ite != listSymbol.end() ; ++ite)
    {
		(*ite)->execute();
    }
}

void Li::execute() {
	// std::cout << "Execute Li" << std::endl; 
	list<Symbol*> listSymbol = this->getListSymbol();
    list<Symbol*>::iterator ite;
    for(ite = listSymbol.begin() ; ite != listSymbol.end() ; ++ite)
    {
		(*ite)->execute();
    }
}

void D::execute() {
	list<Symbol*> listSymbol = this->getListSymbol();
    list<Symbol*>::iterator ite;
	Symbol* type = *(listSymbol.begin());
	// std::cout << "D execute" << std::endl;
	int value = 0;

	// on recherche la valeur
	for(ite = listSymbol.begin() ; ite != listSymbol.end() ; ++ite)
    {
		if ((*ite)->getId() == n) {
			value = ((Nombre*)(*ite))->getVal();
		}
    }
	// on recherche le nom
    for(ite = listSymbol.begin() ; ite != listSymbol.end() ; ++ite)
    {
		if ((*ite)->getId() == id) {
			(type)->execute((*ite)->to_string(),value);
		}
    }
}

void Lcst::execute(){
	list<Symbol*> listSymbol = this->getListSymbol();
    list<Symbol*>::iterator ite;
	// std::cout << "Lcste execute" << std::endl;
	int value = 0;

	// on recupere la valeur du const
	for(ite = listSymbol.begin() ; ite != listSymbol.end() ; ++ite)
    {
		if ((*ite)->getId() == n) {
			value = ((Nombre*)(*ite))->getVal();
		}
    }
	// on recherche le nom de la constante, et on ajoute a la map
    for(ite = listSymbol.begin() ; ite != listSymbol.end() ; ++ite)
    {
		if ((*ite)->getId() == id) {
			Execute::exec_const.insert( std::pair<std::string,const int>((*ite)->to_string(),value) );
		}
    }
}

void Lid::execute(){
	list<Symbol*> listSymbol = this->getListSymbol();
    list<Symbol*>::iterator ite;
	// std::cout << "Lid execute" << std::endl;

	// on recherche le nom de la constante et on ajoute au 
    for(ite = listSymbol.begin() ; ite != listSymbol.end() ; ++ite)
    {
		if ((*ite)->getId() == id) {
			Execute::exec_variables[(*ite)->to_string()] = 0;
		}
	}
}

void I::execute(){
	list<Symbol*> listSymbol = this->getListSymbol();
    list<Symbol*>::iterator ite = listSymbol.begin();
    string input;

    //Pour la verification de l'input
    bool matched = false;
	boost::smatch result;
	boost::regex reg("^-?[0-9]+$");

    // Traitement différent suivant le type d'instruction.
    if((*ite)->getId() == w){
    	std::cout << ((Exp*)(*++ite))->eval() << std::endl;
    }
    else if ((*ite)->getId() == r){
    	while (!matched){
    		std::cout << "Veuillez entrer un nombre entier : ";
	    	std::cin >> input;
			matched = boost::regex_search(input, result, reg,boost::match_single_line);
		}
    	Execute::exec_variables[(*++ite)->to_string()] = boost::lexical_cast<int>(input);
    }
    else{
    	Execute::exec_variables[(*ite)->to_string()] = ((Exp*)(*std::next(ite,2)))->eval();
    }
}

double Exp::eval(){
	list<Symbol*> listSymbol = this->getListSymbol();
    list<Symbol*>::iterator ite = listSymbol.begin();
    std::map<std::string, const int>::iterator it;

    int e1, e2, op;
    

    if((*ite)->getId() == id){
    	it = Execute::exec_const.find((*ite)->to_string());
    	if (it == Execute::exec_const.end()){
    		return Execute::exec_variables.find((*ite)->to_string())->second;
    	}
    	return it->second;
    } 

	else if((*ite)->getId() == n){
		return ((Nombre*)(*ite))->getVal();
	}

	else if((*ite)->getId() == pl){
		return ((Exp*)(*++ite))->eval();
	}

	else {
		e1 = ((Exp*)(*ite))->eval();
		op = ((Exp*)(*++ite))->getId();
		e2 = ((Exp*)(*++ite))->eval();

		switch(op){
			case add:
				return e1 + e2;
				break;

			case ss:
				return e1 - e2;
				break;

			case dv:
				return e1 / e2;
				break;

			case mul:
				return e1 * e2;
				break;
		}
	}
}

void Variable::execute(std::string name, int){
	// std::cout << "Variable execute" << std::endl;
	Execute::exec_variables[name] = 0;
}

void Constante::execute(std::string name, const int value){
	// std::cout << "Constante execute with " << name << " value " << value << std::endl;
	Execute::exec_const.insert( std::pair<std::string,const int>(name,value) );
}