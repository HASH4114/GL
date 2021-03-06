#include <stdio.h>
#include <string>
#include "Regex.h"
#include "Symbol.h"
#include "Symbols.h"

class Parseur 
{
public:
	Parseur(std::string content);
	Symbol* getNextSymbole();

private:
	std::string content;
	Regex reg;
};

