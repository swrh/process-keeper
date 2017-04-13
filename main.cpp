#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

#include <iostream>

#include <stdlib.h>

using namespace std;

namespace po = boost::program_options;

int
main(int argc, char *argv[])
{
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("compression", po::value<int>(), "set compression level")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        cout << desc << endl;
        return EXIT_FAILURE;
    }

    if (vm.count("compression")) {
        cout << "Compression level was set to " << vm["compression"].as<int>() << "." << endl;
    } else {
        cout << "Compression level was not set." << endl;
    }

    return EXIT_SUCCESS;
}

// vim:set sw=4 ts=4 et tw=120:
