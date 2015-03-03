#include <stdio.h>
#include <regex>
#include <string> 
#include <boost/regex.hpp>

class Regex 
{
public:
	Regex(std::string word);
	int findWord(std::string word);
	
private:
	std::vector<boost::regex> regexs;
};
