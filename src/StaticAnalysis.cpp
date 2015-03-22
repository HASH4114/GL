#include "StaticAnalysis.h"

void StaticAnalysis::Analysis(){
	std::ifstream ifs(fileName);
	std::istringstream iss;
	std::string sub;
	std::string line;
	if(ifs.is_open()){
		while(getline(ifs,line)){
			//Split line by ' ', ','
			iss.str(line);
			iss >> sub;
			//If line begins by var then create a symbol ...
			if(!sub.compare("var")){
				iss.str(iss.str()); //On enlève tous les espaces à la suite
				std::vector<std::string> variables;
				std::string str = iss.str();
				boost::split(variables, str, boost::is_any_of(" ,;"));
				//Pour chaque valeur dans variables -> faire le symbole associé
				for(int i = 0; i<variables.size(); i++){
					varValue.insert(std::pair<std::string,Symbol*>(variables.at(i),NULL));
				}
			}
			//If line begins by const then create a symbol ...
			else if(!sub.compare("const")){

			}
			//If line begins by ecrire then see if in the next split there are some var or const that don't exist, that are not initialized
			else if(!sub.compare("ecrire")){

			}
			//If line begins by lire then see if it isn't followed by a const
			else if(!sub.compare("lire")){

			}
		}
		//Go through the Symbol table and see if there are some var that were not used
	}
	else{
		std::cout<< "Unable to open the file" <<std::endl;
	}
}