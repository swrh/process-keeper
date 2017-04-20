#include "application.hpp"

#include <cstring>
#include <iostream>
#include <stdexcept>

#include <stdlib.h>

using namespace std;

extern const char *__progname;

const string program_version("0.0.1");

int
main(int argc, char *argv[])
{
    application app(program_version);

    try {
        app.parse_command_line(argc, argv);
    } catch (exception &e) {
        cerr << __progname << ": " << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// vim:set sw=4 ts=4 et tw=120:
