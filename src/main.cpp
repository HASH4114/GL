#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

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
        //reduction
    }

    if (vm.count("print"))
    {
        display_program_recursive(tomate->getSymbolStackTop());
        // Affichage du programme
    }

    if (vm.count("execution"))
    {

        //reduction

    }
    return 0;
}
