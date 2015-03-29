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
	static int numLigne = 1;
	static int numChar = 1;

	struct match results = {"", 0};
	std::string essai = exp;


	do{

		boost::trim_left_if(essai,boost::is_any_of(" \n\r\t"));
		//~ std::cout << "Testing " << essai <<	 std::endl;

		for ( std::string::iterator it=exp.begin(); *it != essai[0]; ++it){
			if (*it == '\n'){
				numLigne++;
				numChar = 1;
			}
			numChar++;
		}

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
			numChar += results.word.length();
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
			numChar += results.word.length();
			return results;
		}
		if (essai.length() != 0){
			std::cerr << "Erreur lexicale (" << numLigne << ":" << numChar << ") caractere " << essai[0] << std::endl;
			essai = essai.substr(1);
			results.id_symbol = 0;
		}
	}while (essai.length() != 0);

	numChar += results.word.length();
	return results;

}

