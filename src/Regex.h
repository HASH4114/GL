#ifndef REGEX_H
#define REGEX_H

#include <stdio.h>
#include <regex>
#include <string>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>

struct match {
	std::string word;
	int id_symbol;
};

class Regex
{
public:
	Regex();
	struct match findWord(std::string exp);

private:
	std::vector<boost::regex> regexs;
	std::vector<char> symboles;
};

#endif
