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
		exit(0); // RENVOYER DES DOLLARDS 
	}
	std::size_t pos = content.find(results.word);
	if (pos == std::string::npos){
		return NULL; // TODO : Gestion des erreurs
	}

	content = content.substr(pos + results.word.length());
	Symbol* resultat;
	switch (results.id_symbol) {
		case 0 : // +
			 resultat = new 
			 break;
		case 1 : // -
			 
			 break;
		default: 
			exit(25);
	}
	/*
		Regex::symboles.push_back('+');
	Regex::symboles.push_back('-');
	Regex::symboles.push_back('*');
	Regex::symboles.push_back('/');
	Regex::symboles.push_back('(');
	Regex::symboles.push_back(')');
	Regex::symboles.push_back(',');
	Regex::symboles.push_back(';');
	Regex::symboles.push_back('=');
	
	Regex::regexs.push_back(boost::regex ("^var[ \\t\\n\\r]"));
	Regex::regexs.push_back(boost::regex ("^const[ \\t\\n\\r]"));
	Regex::regexs.push_back(boost::regex ("^lire[ \\t\\n\\r]"));
	Regex::regexs.push_back(boost::regex ("^ecrire[ \\t\\n\\r]"));
	Regex::regexs.push_back(boost::regex ("^[a-zA-Z][a-zA-Z0-9]*"));
	Regex::regexs.push_back(boost::regex ("^[0-9]+"));
	Regex::regexs.push_back(boost::regex ("^:="));
}
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
	* */
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

