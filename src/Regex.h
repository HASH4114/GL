#include <stdio.h>
#include <regex>
#include <string> 
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>

class Regex 
{
public:
	Regex();
	std::string findWord(std::string exp);
	
private:
	std::vector<boost::regex> regexs;
	std::vector<char> symboles;
};
