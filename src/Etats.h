#ifndef ETATS_H
#define ETATS_H

#include <iostream>
#include "Etat.h"

using namespace std;

class E0 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E1 : public Etat{
  //Redefinition of the constructor. It seems to be needed.
  //To do with all the states. 
  public:
    E1(string name);
  bool transition (Automate &automate, Symbol *s);

};


class E2 : public Etat{
  public:
    E2(string name);
  bool transition (Automate &automate, Symbol *s);

};


class E3 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E4 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E5 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E6 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E7 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E8 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E9 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E10 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E11 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E12 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E13 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E14 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E15 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E16 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E17 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E18 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E19 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E20 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E21 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E22 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E23 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E24 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E25 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E26 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E27 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E28 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E29 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E30 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E31 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E32 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E33 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E34 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E35 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E36 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E37 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E38 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E39 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E40 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};


class E41 : public Etat{
  bool transition (Automate &automate, Symbol *s);

};

#endif
