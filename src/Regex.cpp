#include "Regex.h"

Regex::Regex()
{
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

struct match Regex::findWord(std::string exp)
{
	struct match results = {"", 0};
	std::string essai = exp;
	boost::trim_left_if(essai,boost::is_any_of(" \n\r\t"));
	//~ std::cout << "Testing " << essai << std::endl;
	
	bool matched;
	std::vector<char>::iterator itchar = symboles.begin();
	// Testons les symboles d'un seul caractere
	do{
		//~ std::cout << "Trying char " << *itchar << std::endl;
		matched = (*itchar == essai[0]);
		++itchar;
		results.id_symbol++;
	}while(!matched && itchar != symboles.end());
	
	if (matched)
	{
		results.word = {*(--itchar)};
		results.id_symbol--;
		return results;
	}
	
	// Testons les expressions regulieres
	boost::smatch result;
	
	std::vector<boost::regex>::iterator it = regexs.begin();
	
	do{
		//~ std::cout << "Trying " << *it << std::endl;
		matched = boost::regex_search(essai, result, *it,boost::match_single_line);
		++it;
		results.id_symbol++;
	}while(!matched && it != regexs.end());

	if (matched)
	{
		//~ std::cout << "[!] Result : " << result[0] << std::endl;
		results.word = result[0];
		results.id_symbol--;
		return results;
	}
	
	return results;

}

