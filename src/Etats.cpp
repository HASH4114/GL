#include "Etats.h"

#include <list>
using namespace std;

bool E0 :: transition (Automate *automate, Symbol *s)
{
	Symbol* ld = new Ld(Lde); //We create a new Symbol Ld in order to push it to the stack.
	switch (*s)
	{
		//Here we define the different cases we can encounter, meaning the different
		//transitions. Next step is to replace with the symbols.
		case Pe:
			automate->shift(s, new E1());
			break;
		case Lde:
		automate->shift(s, new E2());
			break;
		case id: //For id, r, w v and c we do the exact same thing, reducing.
		case r:
		case w:
		case v:
		case c:
			automate->reduce(ld, 0);
			break;
		default:
			break;
	}
	return false;
}



bool E1 :: transition (Automate *automate, Symbol *s)
{
	switch (*s)
	{
		case $:
			//We got to the end of the file so we're finished
			return true;
			break;
		default:
			break;
	}
	return false;
}


bool E2 :: transition (Automate *automate, Symbol *s)
{
	Symbol* li = new Li(Lie); //We create a new Symbol Li in order to push it to the stack.
	std::cout<<"Etat E2:" <<(int)*s<<"dafuk"<<std::endl;
	switch ((int)*s)
	{
		case Lie:
			std::cout<< "there" <<std::endl;
			automate->shift(s, new E3());
			break;
		case De:
			automate->shift(s, new E4());
			break;
		case v:
			std::cout<< "ret here" <<std::endl;
			automate->shift(s, new E5());
			break;
		case c:
			automate->shift(s, new E6());
			break;
		case id: //For id, r, w and $ we do the exact same thing, reducing.
		case r:
		case w:
		case $:
			automate->reduce(li, 0);
			break;
		default:
			break;
	}
	return false;
}



bool E3 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case Ie:
			automate->shift(s, new E7());
			break;
		case r:
			automate->shift(s, new E8());
			break;
		case w:
			automate->shift(s, new E9());
			break;
		case id :
			automate->shift(s, new E10());
			break;
		default:
			break;
	}
	return false;
}



bool E4 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case pv:
			automate->shift(s, new E11());
			break;
		default:
			break;
	}
	return false;
}



bool E5 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case id:
			automate->shift(s, new E12());
			break;
		default:
			break;
	}
	return false;
}



bool E6 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case id:
			automate->shift(s, new E13());
			break;
		default:
			break;
	}
	return false;
}



bool E7 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case pv:
			automate->shift(s, new E14());
			break;
		default:
			break;
	}
	return false;
}



bool E8 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case id:
			automate->shift(s, new E15());
			break;
		default:
			break;
	}
	return false;
}



bool E9 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case Ee:
			automate->shift(s, new E16());
			break;
		case pl:
			automate->shift(s, new E17());
			break;
		case id:
			automate->shift(s, new E18());
			break;
		case n:
			automate->shift(s, new E19());
			break;
		default:
			break;
	}
	return false;
}



bool E10 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case af:
			automate->shift(s, new E20());
			break;
		default:
			break;
	}
	return false;
}



bool E11 :: transition (Automate *automate, Symbol *s){
	Symbol* pv;
	Symbol* D;
	Symbol* firstLd;
	Symbol* ld = new Ld(Lde);
	switch (*s){
		//We do the exact same thing if we encounter id, r, w, v or c.
		//We pop 3 symbols and reduce Ld.
	case id:
	case r:
	case w:
	case v:
	case c:
			firstLd = automate->popS();
			D = automate->popS();
			pv = automate->popS();
			ld->addSymbolToList(pv);
			ld->addSymbolToList(D);
			ld->addSymbolToList(firstLd);
			automate->reduce(ld,3);
			break;
		default:
			break;
	}
	return false;
}



bool E12 :: transition (Automate *automate, Symbol *s){
	Symbol* lid = new Lid(Lide);
	switch (*s){
		case Lide:
			automate->shift(s, new E21());
			break;
		case vi:
		case pv:
			automate->reduce(lid, 0);
			break;
		default:
			break;
	}
	return false;
}



bool E13 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case e:
			automate->shift(s, new E22());
			break;
		default:
			break;
	}
	return false;
}



bool E14 :: transition (Automate *automate, Symbol *s){
	Symbol* lis;
	Symbol* i;
	Symbol* pv;
	Symbol* li = new Li(Lie);
	switch (*s){
		case id:
		case r:
		case w:
		case $:
			pv = automate->popS();
			i = automate->popS();
			lis = automate->popS();
			li->addSymbolToList(lis);
			li->addSymbolToList(i);
			li->addSymbolToList(pv);
			automate->reduce(li, 3);
			break;
		default:
			break;
	}
	return false;
}



bool E15 :: transition (Automate *automate, Symbol *s){
	Symbol* r;
	Symbol* id;
	Symbol* i = new I(Ie);
	switch (*s){
		case pv:
			id = automate->popS();
			r = automate->popS();
			i->addSymbolToList(r);
			i->addSymbolToList(id);
			automate->reduce(i,2);
		default:
			break;
	}
	return false;
}



bool E16 :: transition (Automate *automate, Symbol *s){
	Symbol* w;
	Symbol* e;
	Symbol* i = new I(Ie);
	switch (*s){
		case add:
			automate->shift(s, new E23());
			break;
		case ss:
			automate->shift(s, new E24());
			break;
		case mul:
			automate->shift(s, new E25());
			break;
		case dv:
			automate->shift(s, new E26());
			break;
		case pv:
			e = automate->popS();
			w = automate->popS();
			i->addSymbolToList(w);
			i->addSymbolToList(e);
			automate->reduce(i, 2);
			break;
		default:
			break;
	}
	return false;
}



bool E17 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case pl:
			automate->shift(s, new E17());
			break;
		case id:
			automate->shift(s, new E18());
			break;
		case n:
			automate->shift(s, new E19());
			break;
		case Ee:
			automate->shift(s, new E27());
			break;
		default:
			break;
	}
	return false;
}



bool E18 :: transition (Automate *automate, Symbol *s){
	Symbol* id;
	Symbol* e = new Exp(Ee);
	switch (*s){
		case add:
		case ss:
		case mul:
		case dv:
		case pr:
		case pv:
			id = automate->popS();
			e->addSymbolToList(id);
			automate->reduce(e, 1);
			break;
		default:
			break;
	}
	return false;
}



bool E19 :: transition (Automate *automate, Symbol *s){
	Symbol* n;
	Symbol* e = new Exp(Ee);
	switch (*s){
		case add:
		case ss:
		case mul:
		case dv:
		case pr:
		case pv:
			n = automate->popS();
			e->addSymbolToList(n);
			automate->reduce(e, 1);
			break;
		default:
			break;
	}
	return false;
}



bool E20 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case Ee:
			automate->shift(s, new E28());
			break;
		case pl:
			automate->shift(s, new E17());
			break;
		case id:
			automate->shift(s, new E18());
			break;
		case n:
			automate->shift(s, new E19());
			break;
		default:
			break;
		}
	return false;
}



bool E21 :: transition (Automate *automate, Symbol *s){
	Symbol* v;
	Symbol* id;
	Symbol* lid;
	Symbol* d = new D(De);
	switch (*s){
		case vi:
			automate->shift(s, new E29());
			break;
		case pv:
			lid = automate->popS();
			id = automate->popS();
			v= automate->popS();
			d -> addSymbolToList(v);
			d -> addSymbolToList(id);
			d -> addSymbolToList(lid);
			automate->reduce(d, 3);
			break;
		default:
			break;
	}
	return false;
}



bool E22 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case n :
			automate->shift(s, new E30());
			break;
		default:
			break;
	}
	return false;
}



bool E23 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case Ee:
			automate->shift(s, new E31());
			break;
		case pl:
			automate->shift(s, new E17());
			break;
		case id:
			automate->shift(s, new E18());
			break;
		case n:
			automate->shift(s, new E19());
			break;
		default:
			break;
	}
	return false;
}



bool E24 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case Ee:
			automate->shift(s, new E31());
			break;
		case pl:
			automate->shift(s, new E17());
			break;
		case id:
			automate->shift(s, new E18());
			break;
		case n:
			automate->shift(s, new E19());
			break;
		default:
			break;
	}
	return false;
}



bool E25 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case Ee:
			automate->shift(s, new E31());
			break;
		case pl:
			automate->shift(s, new E17());
			break;
		case id:
			automate->shift(s, new E18());
			break;
		case n:
			automate->shift(s, new E19());
			break;
		default:
			break;
	}
	return false;
}



bool E26 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case Ee:
			automate->shift(s, new E31());
			break;
		case pl:
			automate->shift(s, new E17());
			break;
		case id:
			automate->shift(s, new E18());
			break;
		case n:
			automate->shift(s, new E19());
			break;
		default:
			break;
	}
	return false;
}



bool E27 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case add:
			automate->shift(s, new E23());
			break;
		case ss:
			automate->shift(s, new E24());
			break;
		case mul:
			automate->shift(s, new E25());
			break;
		case dv:
			automate->shift(s, new E26());
			break;
		case pr:
			automate->shift(s, new E41());
			break;
		default:
			break;
	}
	return false;
}



bool E28 :: transition (Automate *automate, Symbol *s){
	Symbol* id;
	Symbol* af;
	Symbol* e;
	Symbol* i = new I(Ie);
	switch (*s){
		case add:
			automate->shift(s, new E23());
			break;
		case ss:
			automate->shift(s, new E24());
			break;
		case mul:
			automate->shift(s, new E25());
			break;
		case dv:
			automate->shift(s, new E26());
			break;
		case pv:
			e = automate->popS();
			af = automate->popS();
			id = automate->popS();
			i->addSymbolToList(id);
			i->addSymbolToList(af);
			i->addSymbolToList(e);
			automate->reduce(i, 3);
			break;
		default:
			break;
	}
	return false;
}



bool E29 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case id:
			automate->shift(s, new E35());
			break;
		default:
			break;
	}
	return false;
}



bool E30 :: transition (Automate *automate, Symbol *s){
	Symbol* lcst = new Lcst(Lcste);
	switch (*s){
		case vi:
		case pv:
			automate->reduce(lcst, 0);
		case Lcste:
			automate->shift(s, new E36());
		default:
			break;
	}
	return false;
}



bool E31 :: transition (Automate *automate, Symbol *s){
	Symbol* e1;
	Symbol* op;
	Symbol* e2;
	Symbol* expr = new Exp(Ee);
	switch (*s){
		case add:
		case ss:
		case pr:
		case pv:
			e2 = automate->popS();
			op = automate->popS();
			e1 = automate->popS();
			expr->addSymbolToList(e1);
			expr->addSymbolToList(op);
			expr->addSymbolToList(e2);
			automate->reduce(expr, 3);
			break;
		case mul:
			automate->shift(s, new E25());
			break;
		case dv:
			automate->shift(s, new E26());
			break;
		default:
			break;
	}
	return false;
}



bool E32 :: transition (Automate *automate, Symbol *s){
	Symbol* e1;
	Symbol* op;
	Symbol* e2;
	Symbol* expr = new Exp(Ee);
	switch (*s){
		case add:
		case ss:
		case pr:
		case pv:
			e2 = automate->popS();
			op = automate->popS();
			e1 = automate->popS();
			expr->addSymbolToList(e1);
			expr->addSymbolToList(op);
			expr->addSymbolToList(e2);
			automate->reduce(expr, 3);
			break;
		case mul:
			automate->shift(s, new E25());
			break;
		case dv:
			automate->shift(s, new E26());
			break;
		default:
			break;
	}
	return false;
}



bool E33 :: transition (Automate *automate, Symbol *s){
	Symbol* e1;
	Symbol* op;
	Symbol* e2;
	Symbol* expr = new Exp(Ee);
	switch (*s){
		case add:
		case ss:
		case mul:
		case dv:
		case pr:
		case pv:
			e2 = automate->popS();
			op = automate->popS();
			e1 = automate->popS();
			expr->addSymbolToList(e1);
			expr->addSymbolToList(op);
			expr->addSymbolToList(e2);
			automate->reduce(expr, 3);
			break;
		default:
			break;
	}
	return false;
}



bool E34 :: transition (Automate *automate, Symbol *s){
	Symbol* e1;
	Symbol* op;
	Symbol* e2;
	Symbol* expr = new Exp(Ee);
	switch (*s){
		case add:
		case ss:
		case mul:
		case dv:
		case pr:
		case pv:
			e2 = automate->popS();
			op = automate->popS();
			e1 = automate->popS();
			expr->addSymbolToList(e1);
			expr->addSymbolToList(op);
			expr->addSymbolToList(e2);
			automate->reduce(expr, 3);
			break;
		default:
			break;
	}
	return false;
}



bool E35 :: transition (Automate *automate, Symbol *s){
	Symbol* lidb;
	Symbol* virg; // Different name because else, it has the same name as vi enum
	Symbol* id;
	Symbol* lid = new Lid(Lide);
	switch (*s){
		case vi:
		case pv:
			id = automate->popS();
			virg = automate->popS();
			lidb = automate->popS();
			lid->addSymbolToList(lidb);
			lid->addSymbolToList(virg);
			lid->addSymbolToList(id);
			automate->reduce(lid, 3);
			break;
		default:
			break;
	}
	return false;
}



bool E36 :: transition (Automate *automate, Symbol *s){
	Symbol* c;
	Symbol* id;
	Symbol* e;
	Symbol* n;
	Symbol* lcstb;
	Symbol* lcst = new Lcst(Lcste);
	switch (*s){
		case vi:
			automate->shift(s, new E37());
			break;
		case pv:
			lcstb = automate->popS();
			n = automate->popS();
			e = automate->popS();
			id = automate->popS();
			c = automate->popS();
			lcst->addSymbolToList(c);
			lcst->addSymbolToList(id);
			lcst->addSymbolToList(e);
			lcst->addSymbolToList(n);
			lcst->addSymbolToList(lcstb);
			automate->reduce(lcst,5);
			break;
		default:
			break;
	}
	return false;
}



bool E37 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case id:
			automate->shift(s, new E38());
			break;
		default:
			break;
	}
	return false;
}



bool E38 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case e:
			automate->shift(s, new E39());
			break;
		default:
			break;
	}
	return false;
}



bool E39 :: transition (Automate *automate, Symbol *s){
	switch (*s){
		case n:
			automate->shift(s, new E40());
			break;
		default:
			break;
	}
	return false;
}



bool E40 :: transition (Automate *automate, Symbol *s){
	Symbol* lcstb;
	Symbol* virg;
	Symbol* id;
	Symbol* e;
	Symbol* n;
	Symbol* lcst = new Lcst(Lcste);
	switch (*s){
		case vi:
		case pv:
			n = automate->popS();
			e = automate->popS();
			id = automate->popS();
			virg = automate->popS();
			lcstb = automate->popS();
			lcst->addSymbolToList(lcstb);
			lcst->addSymbolToList(virg);
			lcst->addSymbolToList(id);
			lcst->addSymbolToList(e);
			lcst->addSymbolToList(n);
			automate->reduce(lcst,5);
			break;
			default:
				break;
		}
	return false;
}



bool E41 :: transition (Automate *automate, Symbol *s){
	Symbol* pl;
	Symbol* e;
	Symbol* pri;
	Symbol* expr = new Exp(Ee);
	switch (*s){
		case add:
		case ss:
		case mul:
		case dv:
		case pr:
		case pv:
			pri = automate->popS();
			e = automate->popS();
			pl = automate->popS();
			expr->addSymbolToList(pl);
			expr->addSymbolToList(e);
			expr->addSymbolToList(pri);
			automate->reduce(expr, 3);
			break;
		default:
			break;
	}
	return false;
}
