#ifndef RESOLVER_H
#define RESOLVER_H

#include <string>

class Resolver {
public:
    static std::string resolve(const std::string &host);
};

#endif