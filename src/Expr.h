#ifndef EXPR_H
#define EXPR_H

#include <iostream>
#include <map>

const int EXPR = 0;

using namespace std;

class Expr : public Symbol {
public:
	Expr():Symbol(EXPR) {}
	virtual ~Expr();
	virtual double eval (const map<string, double> & valeurs) = 0 ;
};

#endif
