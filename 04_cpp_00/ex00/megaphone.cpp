#include <iostream>

std::string str_to_upper(std::string str) {
    for (unsigned long i = 0; i < str.length(); i++) {
        str[i] = std::toupper(str[i]);
    }
    return str;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else {
        for (int i = 1; i < argc; i++) {
            std::cout << str_to_upper(std::string(argv[i]));
        }
    }
    std::cout << std::endl;
    return 0;
}