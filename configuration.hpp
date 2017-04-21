#if !defined(_CONFIGURATION_HPP_)
#define _CONFIGURATION_HPP_

#include <boost/property_tree/ptree.hpp>

#include <list>
#include <string>
#include <vector>

class
configuration
{
public:
    struct
    process
    {
        std::string name;
        std::string cwd;
        std::string exe;
        std::vector<std::string> args;

        std::string to_string() const;
    };

private:
    boost::property_tree::ptree tree;

    std::list<process> processes;
    std::string log;

public:
    configuration();
    virtual ~configuration();

    void read_file(const std::string &path);
};

#endif // !defined(_CONFIGURATION_HPP_)

// vim:set sw=4 ts=4 et tw=120:
