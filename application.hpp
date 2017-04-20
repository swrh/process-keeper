#if !defined(_APPLICATION_HPP_)
#define _APPLICATION_HPP_

#include <string>

class
application
{
private:
    const std::string version;

public:
    application(const std::string &version);
    virtual ~application();

    void parse_command_line(int argc, char *argv[]);
};

#endif // !defined(_APPLICATION_HPP_)

// vim:set sw=4 ts=4 et tw=120:
