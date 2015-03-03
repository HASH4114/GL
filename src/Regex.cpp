#include "Regex.h"

Regex::Regex(std::string word)
{
	Regex::regexs.push_back(boost::regex ("lire\\s"));
	Regex::regexs.push_back(boost::regex ("ecrire\\s"));
	Regex::regexs.push_back(boost::regex ("var\\s"));
	Regex::regexs.push_back(boost::regex ("[a-zA-Z][a-zA-Z0-9]*"));
}


int Regex::findWord(std::string word)
{
	std::string essai = "var abc08e;";
	
	boost::match_results<std::string::const_iterator> result;
	std::vector<boost::regex>::iterator it = regexs.begin(); 
	
	do{
		regex_match(essai, result, *it);
		++it;
	}while(result.empty() && it != regexs.end());
	
	std::cout << result[0] << std::endl;
	
	//~ switch(result[0])
	//~ {
//~ 
	//~ }	

	

}

