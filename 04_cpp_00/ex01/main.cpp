#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;

    std::string cmd;
    while (!std::cin.eof()) {
        std::cout << "Enter a command (ADD / SEARCH / EXIT ): ";
        std::getline(std::cin, cmd);

        if (cmd.empty())
            continue;
        if (cmd == "ADD" || cmd == "add")
            phoneBook.addContact();
        else if (cmd == "SEARCH" || cmd == "search")
            phoneBook.searchContact();
        else if (cmd == "EXIT" || cmd == "exit")
            break;
        else
            std::cout << "[ERROR] Invalid Command" << std::endl;
    }
}