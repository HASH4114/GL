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
		resultat = new Symbol(dol);
		return resultat;
	}

	std::size_t pos = content.find(results.word);

	if (pos == std::string::npos){
		return NULL; // TODO : Gestion des erreurs
	}

	content = content.substr(pos + results.word.length());

	switch (results.id_symbol) {
		case 0 : // +
			resultat = new ExpPlus(add);
			break;
		case 1 : // -
			resultat = new ExpMoins(ss);
			break;
		case 2 : // *
			resultat = new ExpMult(mul);
			break;
		case 3 : // /
			resultat = new ExpDiv(dv);
			break;
		case 4 : // (
			resultat = new ExpParG(pl);
			break;
		case 5 : // )
			resultat = new ExpParD(pr);
			break;
		case 6 : // ,
			resultat = new ExpVir(vi);
			break;
		case 7 : // ;
			resultat = new ExpPv(pv);
			break;
		case 8 : // =
			resultat = new ExpEg(e);
			break;
		case 9 : // var
			resultat = new Variable(v);
			break;
		case 10 : // const
			resultat = new Constante(c);
			break;
		case 11 : // lire
			resultat = new Symbol(r);
			break;
		case 12 : // ecrire
			resultat = new Symbol(w);
			break;
		case 13 : // id
			resultat = new Id(id, results.word);
			break;
		case 14 : // nb
			resultat = new Nombre(n, std::stoi(results.word));
			break;
		case 15 : // :=
 	 		resultat = new Symbol(af);
		 	break;
		default: 
			return NULL;
	}
	return resultat;
}
/*
int main()
{
	std::string content = "var y,u; const c = 5;";
	Parseur p(content);
	int i = 0;
	while (i<5){
		std::cout << *p.getNextSymbole() << std::endl;		
		i++;
	}
}*/

