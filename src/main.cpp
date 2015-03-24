#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "Etats.h"
#include "Expr.h"

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


    // gestion des arguments

    if (vm.count("print"))
    {
        // Affichage du programme
    }

    if (vm.count("analyse"))
    {
        
        //analyse statique
    }

    if (vm.count("execution"))
    {
        //execution
    }

    if (vm.count("transformation"))
    {
        //reduction
    }

    /*
    Automate* tomate = new Automate();
    list<int> listTest = {v,id,vi,id,vi,id,pv,c,id,e,n,pv,c,id,e,n,pv,v,id,pv,id,af,pl,id,add,id,pr,mul,n,ss,n,pv};
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
        std::cout << e->getName() << std::endl ;
        e->transition(tomate, *iteSymb);
    }*/

    return 0;
}
