#include "Regex.h"

Regex::Regex()
{
	Regex::regexs.push_back(boost::regex ("^var[ \\t\\n\\r]"));
	Regex::regexs.push_back(boost::regex ("^const[ \\t\\n\\r]"));
	Regex::regexs.push_back(boost::regex ("^lire[ \\t\\n\\r]"));
	Regex::regexs.push_back(boost::regex ("^ecrire[ \\t\\n\\r]"));
	Regex::regexs.push_back(boost::regex ("^[a-zA-Z][a-zA-Z0-9]*"));
	Regex::regexs.push_back(boost::regex ("^[0-9]+"));
	Regex::regexs.push_back(boost::regex ("^:="));
	
	Regex::symboles.push_back(';');
	Regex::symboles.push_back('=');
	Regex::symboles.push_back('+');
	Regex::symboles.push_back('-');
	Regex::symboles.push_back('*');
	Regex::symboles.push_back('/');
	Regex::symboles.push_back(',');
	Regex::symboles.push_back('(');
	Regex::symboles.push_back(')');
}


std::string Regex::findWord(std::string exp)
{
	std::string essai = exp;
	boost::trim_left_if(essai,boost::is_any_of(" \n\r\t"));
	std::cout << "Testing " << essai << std::endl;
	
	bool matched;
	std::vector<char>::iterator itchar = symboles.begin();
	// Testons les symboles d'un seul caractere
	do{
		std::cout << "Trying char " << *itchar << std::endl;
		matched = (*itchar == essai[0]);
		++itchar;
	}while(!matched && itchar != symboles.end());
	
	if (matched)
	{
		std::string caractere({*(--itchar)});
		return caractere;
	}
	
	// Testons les expressions regulieres
	boost::smatch result;
	
	std::vector<boost::regex>::iterator it = regexs.begin();
	
	do{
		std::cout << "Trying " << *it << std::endl;
		matched = boost::regex_search(essai, result, *it);
		++it;
	}while(!matched && it != regexs.end());

	if (matched)
	{
		std::cout << "[!] Result : " << result[0] << std::endl;
		return result[0];
	}
	return "";
	// std::cout << (result[0].first) << std::endl;
	// std::cout << (result[0].second) << std::endl;
	//~ switch(result[0])
	//~ {
//~ 
	//~ }	

	

}

int main()
{
	//std::string content = "var abc; var a;abc=5; ecrire abc; lire a; ecrire a;";
	
	 
	Regex re;
	std::cout << re.findWord(" \n var\nabc;") << std::endl;
	std::cout << re.findWord("lire v;") << std::endl;
	std::cout << re.findWord("_a v;") << std::endl;
	std::cout << re.findWord(";") << std::endl;
	std::cout << re.findWord("fdjvbduvgudf") << std::endl;
}

