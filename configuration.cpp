#include "configuration.hpp"

#include <boost/property_tree/xml_parser.hpp>

#include <cstring>
#include <iostream>

using namespace std;
using namespace boost;

configuration::configuration()
{
}

configuration::~configuration()
{
}

void
configuration::read_file(const string &path)
{
    property_tree::read_xml(path, tree);

    cout << "log: " << tree.get<std::string>("process-keeper.log") << endl;
    for (property_tree::ptree::value_type &v : tree.get_child("process-keeper")) {
        if (strcmp(v.first.data(), "process") == 0) {
            cout << v.first.data() << ": " << v.second.get<std::string>("name");
            for (property_tree::ptree::value_type &w : v.second.get_child("args")) {
                cout << " " << w.second.data();
            }
            cout << endl;
        }
    }
}

// vim:set sw=4 ts=4 et tw=120:
