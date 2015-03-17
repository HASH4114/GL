#include <stdio.h>
#include <string>

enum Symbole{};

class Parseur 
{
public:
	Parseur(std::string content);
	Symbole getNextSymbole();
	
private:
	std::string content;
};
