#include "cli.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "../scanner/scanner.h"

void CLI::start() {
    std::string input;

    std::cout << "=====================================\n";
    std::cout << "   CyberScanner CLI Framework 🚀\n";
    std::cout << "=====================================\n";

    while (true) {
        std::cout << "\ncyber> ";
        std::getline(std::cin, input);

        std::stringstream ss(input);
        std::string command;
        ss >> command;

        if (command == "exit") {
            std::cout << "[*] Exiting...\n";
            break;
        }

        else if (command == "help") {
            std::cout << "\nAvailable Commands:\n";
            std::cout << "  scan <target> <start_port> <end_port> <threads>\n";
            std::cout << "  help\n";
            std::cout << "  exit\n";
        }

        else if (command == "scan") {
            std::string target;
            int start, end, threads;

            ss >> target >> start >> end >> threads;

            if (target.empty()) {
                std::cout << "Usage: scan <target> <start_port> <end_port> <threads>\n";
                continue;
            }

            Scanner scanner;
            scanner.run(target, start, end, threads);
        }

        else {
            std::cout << "[-] Unknown command. Type 'help'\n";
        }
    }
}