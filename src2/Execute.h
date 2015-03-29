#ifndef EXECUTE_H
#define EXECUTE_H

#include <map>
#include "Symbols.h"
#include "Symbol.h"

class Execute
{
	public:
		Execute(Symbol* p);

		static std::map<std::string, int> exec_variables;
		static std::map<std::string, const int> exec_const;
		void run();		 
	private:
		Symbol* top;
};

#endif