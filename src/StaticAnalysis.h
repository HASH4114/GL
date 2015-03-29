#ifndef STATICANALYSiS_H
#define STATICANALYSIS_H

#include <string>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/constants.hpp>
#include <boost/regex.hpp>
#include <regex>
#include <typeinfo>
#include "Symbol.h"
#include "Symbols.h"

class StaticAnalysis
{
	public:
		StaticAnalysis();
		virtual ~StaticAnalysis();
		bool Analysis(Symbol* p);
	private:
		std::map<std::string, Symbol*> varValue;		//Table des symboles
		std::string fileName;
		std::list<Symbol*> listSymbol;
		void getAllSymbols(Symbol* p);
		std::string varUnknown(std::list<Symbol*>::iterator begining);
};

#endif
