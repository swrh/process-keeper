#if !defined(_CONFIGURATION_HPP_)
#define _CONFIGURATION_HPP_

#include <boost/property_tree/ptree.hpp>

#include <string>

class
configuration
{
private:
    boost::property_tree::ptree tree;

public:
    configuration();
    virtual ~configuration();

    void read_file(const std::string &path);
};

#endif // !defined(_CONFIGURATION_HPP_)

// vim:set sw=4 ts=4 et tw=120:
