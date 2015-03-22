#ifndef STATICANALYSiS_H
#define STATICANALYSIS_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/constants.hpp>
#include "Symbol.h"

class StaticAnalysis
{
	public:
		StaticAnalysis(std::string fileName);
		virtual ~StaticAnalysis();
		void Analysis();
	private:
		std::map<std::string, Symbol*> varValue;		//Table des symboles
		std::string fileName;
};

#endif
