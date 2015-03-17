#include "Parseur.h"

Parseur::Parseur(std::string content)
{
	Parseur::content = content;
	Parseur::reg = Regex();
}


Symbol* Parseur::getNextSymbole(){
	struct match results = reg.findWord(content);
	// Gestion du cas word = ""
	if (results.word == "") 
	{
		exit(0); // RENVOYER DES DOLLARDS BIAZTZTZE
	}
	std::size_t pos = content.find(results.word);
	if (pos == std::string::npos){
		return NULL; // TODO : Gestion des erreurs
	}

	content = content.substr(pos + results.word.length());
	
	return new Symbol(results.id_symbol);
}

int main()
{
	std::string content = "var abc; var a;abc=5; ecrire abc; lire a; ecrire a;";
	Parseur p(content);
	while (1){
		std::cout << (int)*p.getNextSymbole() << std::endl;		
	}
}

