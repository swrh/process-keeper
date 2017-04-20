#include "application.hpp"

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <cstring>
#include <iostream>

using namespace std;
using namespace boost;

application::application(const string &version)
    : version(version)
{
}

application::~application()
{
}

void
application::parse_command_line(int argc, char *argv[])
{
    program_options::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("version,v", "print version string")
        ("config-file,c", program_options::value<string>()->default_value("process-keeper.xml"), "set the configuration file")
        ;

    program_options::variables_map vm;
    program_options::store(program_options::parse_command_line(argc, argv, desc), vm);
    program_options::notify(vm);

    if (vm.count("help")) {
        cout << desc << endl;
        exit(EXIT_SUCCESS);
    }

    if (vm.count("version")) {
        cout << version << endl;
        exit(EXIT_SUCCESS);
    }

    if (vm.count("config-file")) {
        cfg.read_file(vm["config-file"].as<string>());
    }
}

// vim:set sw=4 ts=4 et tw=120:
