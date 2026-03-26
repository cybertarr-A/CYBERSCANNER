#include "resolver.h"
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>

std::string Resolver::resolve(const std::string &host) {
    hostent *he = gethostbyname(host.c_str());
    if (!he) {
        std::cerr << "[-] Failed to resolve host\n";
        exit(1);
    }

    in_addr **addr_list = (in_addr **)he->h_addr_list;
    return std::string(inet_ntoa(*addr_list[0]));
}