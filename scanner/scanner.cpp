#include "scanner.h"
#include "../utils/resolver.h"

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

#define TIMEOUT_SEC 1

std::mutex print_mutex;

std::string Scanner::grab_banner(int sock) {
    char buffer[1024] = {0};
    send(sock, "HEAD / HTTP/1.1\r\n\r\n", 18, 0);

    int len = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (len > 0) return std::string(buffer);

    return "";
}

void Scanner::scan_port(const std::string &ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return;

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);

    timeval timeout{};
    timeout.tv_sec = TIMEOUT_SEC;

    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

    if (connect(sock, (sockaddr *)&addr, sizeof(addr)) == 0) {
        std::lock_guard<std::mutex> lock(print_mutex);
        std::cout << "[OPEN] Port " << port;

        std::string banner = grab_banner(sock);
        if (!banner.empty())
            std::cout << " | " << banner.substr(0, 50);

        std::cout << "\n";
    }

    close(sock);
}

void Scanner::run(const std::string &target, int start_port, int end_port, int threads) {
    std::cout << "[*] Resolving...\n";
    std::string ip = Resolver::resolve(target);
    std::cout << "[*] Target IP: " << ip << "\n";

    std::vector<std::thread> pool;

    for (int port = start_port; port <= end_port; ++port) {
        pool.emplace_back(scan_port, ip, port);

        if (pool.size() >= threads) {
            for (auto &t : pool) t.join();
            pool.clear();
        }
    }

    for (auto &t : pool) t.join();

    std::cout << "[*] Scan complete.\n";
}