#include "Etats.h"
#include "Symbol.h"

#include <list>
using namespace std;

bool E0 :: transition (Automate &automate, Symbol *s)
{
  switch (*s)
  {
    //Here we define the different cases we can encounter, meaning the different
    //transitions. Next step is to replace with the symbols.
    case Pe:
      automate.shift(*s, new E1());
      break;
    case Lde:
    automate.shift(*s, new E1());
      break;
    default:
      break;
  }
  return false;
}



bool E1 :: transition (Automate &automate, Symbol *s)
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


bool E2 :: transition (Automate &automate, Symbol *s)
{
  switch (*s)
  {
    case Lie:
      automate.shift(*s, new E3());
      break;
    case De:
      automate.shift(*s, new E4());
      break;
    case v:
      automate.shift(*s, new E5());
      break;
    case c:
      automate.shift(*s, new E6());
      break;
    case id:
      Symbol li = new Li(); //We create a new Symbol Li in order to push it to the stack.
      automate.reduce(li, 0);
      break;
    case r:
      Symbol li = new Li(); //We create a new Symbol Li in order to push it to the stack.
      automate.reduce(li, 0);
      break;
    case w:
      Symbol li = new Li(); //We create a new Symbol Li in order to push it to the stack.
      automate.reduce(li, 0);
      break;
    case $:
      Symbol li = new Li(); //We create a new Symbol Li in order to push it to the stack.
      automate.reduce(li, 0);
      break;
    default:
      break;
  }
  return false;
}



bool E3 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    case id :
      automate.shift(*s, new E10());
      break;
    case r:
      automate.shift(*s, new E8());
      break;
    case w:
      automate.shift(*s, new E9());
      break;
    case Ie:
      automate.shift(*s, new E7());
      break;
    default:
      break;
  }
  return false;
}



bool E4 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    case pv:
      automate.shift(*s, new E11());
      break;
    default:
      break;
  }
  return false;
}



bool E5 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    case id:
      automate.shift(*s, new E12());
      break;
    default:
      break;
  }
  return false;
}



bool E6 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    case id:
      automate.shift(*s, new E13());
      break;
    default:
      break;
  }
  return false;
}



bool E7 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    case pv:
      automate.shift(*s, new E14());
      break;
    default:
      break;
  }
  return false;
}



bool E8 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    case id:
      automate.shift(*s, new E15());
      break;
    default:
      break;
  }
  return false;
}



bool E9 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    case id:
      automate.shift(*s, new E18());
      break;
    case pl:
      automate.shift(*s, new E17());
      break;
    case n:
      automate.shift(*s, new E19());
      break;
    case Ee:
      automate.shift(*s, new E16());
      break;
    default:
      break;
  }
  return false;
}



bool E10 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    case af:
      automate.shift(*s, new E20());
      break;
    default:
      break;
  }
  return false;
}



bool E11 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    case id:
      Symbol pv = automate.popS();
      Symbol D = automate.popS();
      Symbol firstLd = automate.popS();
      Symbol ld = new Ld();
      ld.addSymbolToList(pv);
      ld.addSymbolToList(D);
      ld.addSymbolToList(firstLd);
      automate.reduce(ld,3);
      break;
    default:
      break;
  }
  return false;
}



bool E12 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E13 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E14 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E15 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E16 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E17 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E18 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E19 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E20 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E21 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E22 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E23 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E24 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E25 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E26 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E27 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E28 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E29 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E30 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E31 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E32 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E33 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E34 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E35 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E36 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E37 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E38 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E39 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E40 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}



bool E41 :: transition (Automate &automate, Symbol *s){
  switch (*s){
    default:
      break;
  }
  return false;
}
