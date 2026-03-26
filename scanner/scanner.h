#ifndef SCANNER_H
#define SCANNER_H

#include <string>

class Scanner {
public:
    void run(const std::string &target, int start_port, int end_port, int threads);

private:
    static void scan_port(const std::string &ip, int port);
    static std::string grab_banner(int sock);
};

#endif