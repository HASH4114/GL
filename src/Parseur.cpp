#include "Parseur.h"

Parseur::Parseur(std::string content)
{
	Parseur::content = content;
	Parseur::reg = Regex();
}


Symbol* Parseur::getNextSymbole(){
	struct match results = reg.findWord(content);
	Symbol* resultat;

	// Gestion du cas word = ""
	if (results.word == "") 
	{
		resultat = new Symbol($);
		return resultat; // RENVOYER DES DOLLARDS 
	}

	std::size_t pos = content.find(results.word);

	if (pos == std::string::npos){
		return NULL; // TODO : Gestion des erreurs
	}

	content = content.substr(pos + results.word.length());

	switch (results.id_symbol) {
		case 0 : // +
			resultat = new ExpPlus(results.id_symbol);
			break;
		case 1 : // -
			resultat = new ExpMoins(results.id_symbol);
			break;
		case 2 : // *
			resultat = new ExpMult(results.id_symbol);
			break;
		case 3 : // /
			resultat = new ExpDiv(results.id_symbol);
			break;
		case 4 : // (
			resultat = new ExpUnaire(results.id_symbol);
			break;
		case 5 : // )
			resultat = new ExpUnaire(results.id_symbol);
			break;
		case 6 : // ,
			resultat = new ExpUnaire(results.id_symbol);
			break;
		case 7 : // ;
			resultat = new ExpUnaire(results.id_symbol);
			break;
		case 8 : // =
			resultat = new ExpUnaire(results.id_symbol);
			break;
		case 9 : // var
			resultat = new Variable(results.id_symbol);
			break;
		case 10 : // const
			resultat = new Constante(results.id_symbol);

			break;
		case 11 : // lire
			resultat = new Symbol(results.id_symbol);
			break;
		case 12 : // ecrire
			resultat = new Symbol(results.id_symbol);
			break;
		case 13 : // id
			resultat = new Id(results.id_symbol);
			break;
		case 14 : // nb
			resultat = new Nombre(results.id_symbol);
			break;
		case 15 : // assign
 	 		resultat = new Symbol(results.id_symbol);
		 	break;
		default: 
			exit(25);
	return resultat;
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

int Parseur::mainBis()
{
	std::string content = "var y,u; const c = 5;";
	Parseur p(content);
	while (1){
		std::cout << *p.getNextSymbole(). << std::endl;		
	}
}

