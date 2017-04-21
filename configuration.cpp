#include "configuration.hpp"

#include <boost/property_tree/xml_parser.hpp>

#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;
using namespace boost;

string
configuration::process::to_string() const
{
    ostringstream os;

    if (name.size() > 0)
        os << "name(" << name << ") ";

    if (cwd.size() > 0)
        os << "cwd(" << cwd << ") ";

    if (args.size() > 0) {
        os << "args(";
        for (int i = 0; i < args.size(); i++) {
            if (i > 0)
                os << ", ";
            os << args[i];
        }
        os << ") ";
    }

    os << "exe(" << exe << ")";

    return os.str();
}

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

    for (property_tree::ptree::value_type &v : tree.get_child("process-keeper")) {
        string node_name = v.first.data();
        const property_tree::ptree &node = v.second;
        try {
            if (!node_name.compare("process")) {
                process p;
                optional<const property_tree::ptree &> child;

                child = node.get_child_optional("name");
                if (child)
                    p.name = child->data();

                child = node.get_child_optional("cwd");
                if (child)
                    p.cwd = child->data();

                p.exe = node.get<string>("exe");

                child = node.get_child_optional("args");
                if (child)
                    for (const property_tree::ptree::value_type &w : *child)
                        p.args.push_back(w.second.data());

                processes.push_back(p);

                cout << p.to_string() << endl;
            } else if (!node_name.compare("log")) {
                log = node.data();

                cout << "log(" << log << ")" << endl;
            }
        } catch (std::exception &e) {
            cerr << path << ": " << node_name << ": " << e.what() << endl;
        }
    }
}

// vim:set sw=4 ts=4 et tw=120:
