#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <typeinfo>

#include "Etats.h"
#include "Expr.h"
#include "Parseur.h"
#include "StaticAnalysis.h"


#include "boost/program_options.hpp"

void print_error(int id)
{
    switch(id)
    {
        case 1:
            std::cerr << "No input file given" << std::endl;
            std::cerr << "Usage : ./Analyseur [-h,--help|-p,--print|-e,--execution|-o,--transformation] <Lutin source>" << std::endl;
            break;
        case 2:
            std::cerr << "Extension not valid, should be .lt" << std::endl;
            break;
        case 3:
            std::cerr << "Can't open file" << std::endl;
            break;
    }
}

void display_program_recursive(Symbol* p)
{
    list<Symbol*> listSymbol = p->getListSymbol();
    list<Symbol*>::iterator ite;

    for(ite = listSymbol.begin() ; ite != listSymbol.end() ; ++ite)
    {
        if((*ite)->getListSymbol().empty())
        {
            std::cout<<(*ite)->to_string();
        }else{
            display_program_recursive(*ite);
        }
    }
}

void neutralization_recursive(Symbol* p){
  list<Symbol*> listSymbol = p->getListSymbol();
  list<Symbol*>::iterator ite;
  for (ite = listSymbol.begin(); ite != listSymbol.end(); ++ite)
  {
    //If the symbol is composed by other symbols
    if (!(*ite)->getListSymbol().empty())
    {
      //If the symbol is an expression
      if ((**ite) == Ee)
      {

        if ((*ite)->getListSymbol().size() == 3)
        {
          //Stocking the 3 symbols
          Symbol* s1;
          Symbol* s2;
          Symbol* s3;
          list<Symbol*> l = (*ite)->getListSymbol();
          s1 = l.front();
          l.pop_front();
          s2 = l.front();
          l.pop_front();
          s3 = l.front();
          l.pop_front();

          //We get pointers on the numbers
          //If it's not a number, it's not 0 or 1 so the if fails and it's okay.
          Nombre* s1n=nullptr;
          Nombre* s3n=nullptr;
          if(s1->getListSymbol().size()==1)
          {s1n = dynamic_cast<Nombre*>(s1->getListSymbol().front());}
          if(s3->getListSymbol().size()==1)
          {s3n = dynamic_cast<Nombre*>(s3->getListSymbol().front());}

          //Neutral element for addition
          if (*s2 == add){

            //Case +0 and dynamic cast didnt replace by a null pointer
            if((s3n!=nullptr) and (s3n->getVal()==0))
            {
              l.push_front(s1);
              //we replace the list of symbol of the expression by a simple nb symbol
              (*ite)->setListSymbol(l);
            }
            //Case 0+ and dynamic cast didnt replace by a null pointer
            else if((s1n != nullptr) and (s1n->getVal()==0))
            {
              l.push_front(s3);
              //we replace the list of symbol of the expression by a simple nb symbol
              (*ite)->setListSymbol(l);
            }
          }

          //Neutral element for substraction
          else if(*s2 == ss){

            //Case -0 and dynamic cast didnt replace by a null pointer
            if((s3n!=nullptr) and (s3n->getVal()==0))
            {
              l.push_front(s1);
              //we replace the list of symbol of the expression by a simple nb symbol
              (*ite)->setListSymbol(l);
            }
            //Case 0- and dynamic cast didnt replace by a null pointer
            else if((s1n != nullptr) and (s1n->getVal()==0))
            {
              s3n->setVal(-(s3n->getVal()));
              l.push_front(s3);
              //we replace the list of symbol of the expression by a simple nb symbol
              (*ite)->setListSymbol(l);
            }
          }

          //Neutral element for multiplication
          else if(*s2 == mul)
          {

            //Case *1 and dynamic cast didnt replace by a null pointer
            if((s3n!=nullptr) and (s3n->getVal()==1))
            {
              l.push_front(s1);
              //we replace the list of symbol of the expression by a simple nb symbol
              (*ite)->setListSymbol(l);
            }
            //Case 1* and dynamic cast didnt replace by a null pointer
            else if((s1n != nullptr) and (s1n->getVal()==1))
            {
              l.push_front(s3);
              //we replace the list of symbol of the expression by a simple nb symbol
              (*ite)->setListSymbol(l);
            }
            

          }

          //Neutral element for division
          else if(*s2 == dv)
          {

            //Case /1 and dynamic cast didnt replace by a null pointer
            if((s3n!=nullptr) and (s3n->getVal()==1))
            {
              l.push_front(s1);
              (*ite)->setListSymbol(l);
            }
            //we replace the list of symbol of the expression by a simple nb symbol
          }
        }
        neutralization_recursive(*ite);
      }
      else
      {
        neutralization_recursive(*ite);
      }
    }
    //Else, if it not composed of other symbols, nothing to do
  }
}

int main(int argc, char *argv[])
{


    namespace po = boost::program_options;
    po::options_description desc("Options");
    std::string content;
    desc.add_options() ("help,h", "Print help messages")
                    ("print,p", "Affichage du programme")
                    ("execution,e", "Execution du programme")
                    ("transformation,o", "Transformation du programme pour simplifier")
    ;
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    //fichier fourni ?
    std::string last(argv[argc-1]);
    if(argc < 2 || (last != "-h" && last != "--help" && last[last.size()-1] == '-'))
    {
        print_error(1);
        return 127;
    }

    if (vm.count("help"))
    {
        std::cout << "Usage : " << argv[0] << "[-h,--help|-p,--print|-e,--execution|-o,--transformation] <Lutin source>" << std::endl;
        std::cout << desc << std::endl;
        return 0;
    }

    if(last.find_last_of(".lt") != last.size()-1)
    {
        print_error(2);
        return 2;
    }

    std::ifstream ifs(last.c_str());
    if(ifs.fail()) // Fichier valide ?
    {
        print_error(3);
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
        return 1;
    }

    content.assign( (std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()) );
    Automate* tomate = new Automate();
    Etat* e;
    Parseur parseur(content);
    Symbol* symbol;
    do
    {
        symbol = parseur.getNextSymbole();
        e = tomate->getStateStackTop();
        e->transition(tomate, symbol);
    }while(symbol->getId() != dol);


    //analyse statique
    StaticAnalysis sa;
    bool goOn;
    goOn = sa.Analysis(tomate->getSymbolStackTop());

    if (!goOn){
      return 0;
    }

    // gestion des arguments

    if (vm.count("transformation"))
    {
        neutralization_recursive(tomate->getSymbolStackTop());
    }

    if (vm.count("print"))
    {
        display_program_recursive(tomate->getSymbolStackTop());
        // Affichage du programme
    }

    if (vm.count("execution"))
    {
        Execute execution(tomate->getSymbolStackTop());
        std::cout << tomate->getSymbolStackTop()->to_string() << std::endl;
        execution.run();
    }
    return 0;
}
