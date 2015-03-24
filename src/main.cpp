#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "Etats.h"
#include "Expr.h"
#include "Parseur.h"


#include "boost/program_options.hpp"

void print_error(int id)
{
    switch(id)
    {
        case 1:
            std::cerr << "No input file given" << std::endl;
            std::cerr << "Usage : ./Analyseur [-h,--help|-p,--print|-a,--analyse|-e,--execution|-o,--transformation] <Lutin source>" << std::endl;
            break;
        case 2:
            std::cerr << "Extension not valid, should be .lt" << std::endl;
            break;
        case 3:
            std::cerr << "Can't open file" << std::endl;
            break;
    }
}

//Option diplay program
string display_program(Symbol* p)
{

    list<Symbol*> listSymb = p->getListSymbol(); //
    list<Symbol*> tmp;
    list<Symbol*>::iterator it;
    for (it = listSymb.begin(); it!=listSymb.end() ; ++it)
    {
        tmp = (*it)->getListSymbol();
        listSymb.insert(it,tmp.begin(),tmp.end());
    }

    string result ="";
    list<Symbol*>::iterator ite;
    for(ite = listSymb.begin();ite != listSymb.end();++ite)
    {
        std::cout<< "i'm in da loop ! "<<std::endl;
        result += (*ite)->to_string();
    }
    return result;
}


int main(int argc, char *argv[])
{

    
    namespace po = boost::program_options;
    po::options_description desc("Options");
    std::string content;
    desc.add_options() ("help,h", "Print help messages")
                    ("print,p", "Affichage du programme")
                    ("analyse,a", "Analyse statique du programme")
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
        return 1;
    }

    if (vm.count("help"))
    {
        std::cout << "Usage : " << argv[0] << " [-h,--help|-p,--print|-a,--analyse|-e,--execution|-o,--transformation] <Lutin source>" << std::endl;
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
        return 3;
    }

    content.assign( (std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()) );
    Automate* tomate = new Automate();
    Etat* e;
    Parseur parseur(content);
    Symbol* symbol;
    do
    {
        symbol = parseur.getNextSymbole();
        std::cout<<symbol->to_string();
        e = tomate->getStateStackTop();
        //std::cout << e->getName() << std::endl ; //Affichage des états
        e->transition(tomate, symbol);
    }while(symbol->getId() != dol);

    // gestion des arguments

    if (vm.count("analyse"))
    {

        //analyse statique
    }

    if (vm.count("transformation"))
    {
        //reduction
    }

    if (vm.count("print"))
    {
        std::cout << "Enter in display_program"<<std::endl;
        std::cout<<display_program(tomate->getSymbolStackTop());
        // Affichage du programme
    }

    if (vm.count("execution"))
    {

        //reduction
        
    }
    /*Automate* tomate = new Automate();
        //execution
    }*/

/*
    Automate* tomate = new Automate();
    list<int> listTest = {v,id,vi,id,vi,id,pv,dol};
    list<Symbol*> listSymb;
    list<int>::iterator iterator;
    for (iterator = listTest.begin(); iterator != listTest.end(); ++iterator) {
        Symbol* s = new Symbol(*iterator);
        listSymb.push_back(s);

    }
    list<Symbol*>::iterator iteSymb;
    Etat* e;
    for(iteSymb = listSymb.begin(); iteSymb != listSymb.end() ; ++iteSymb ){

        e = tomate->getStateStackTop();
        e->transition(tomate, *iteSymb);
    }

    display_program(tomate->getSymbolStackTop());*/
    return 0;
}

/*
string display_program(list<Symbol*> listSymb)
{
    string result ="";
    list<Symbol*>::iterator ite;
    for(ite = listSymb.begin();ite != listSymb.end();++ite)
    {
        //result += *ite->to_string();
    }
    return result;
}*/
