#include <iostream>
#include <fstream>
#include <string>

#include "Etat.h"
#include "Expr.h"

#include "boost/program_options.hpp"

int main(int argc, char *argv[])
{
    namespace po = boost::program_options;
    po::options_description desc("Options");
    desc.add_options() ("help,", "Print help messages")
                    ("print,p", "Affichage du programme")
                    ("analyse,a", "Analyse statique du programme")
                    ("execution,e", "Execution du programme")
                    ("transformation,o", "Transformation du programme pour simplifier")
                    ("file,f", po::value<std::string>()->required(), "Source file")
    ;
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    // gestion des arguments
    if (vm.count("help"))
    {
        cout << desc << "\n";
        return 1;
    }

    if (vm.count("file"))
    {
        std::ifstream ifs(vm["file"].as<std::string>().c_str());
        std::string content( (std::istreambuf_iterator<char>(ifs) ), (std::istreambuf_iterator<char>()) );
        // pour mastho et felix
        //appel au parseur avec content
    }

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

    return 0;
}
