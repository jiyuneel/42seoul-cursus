#include <iostream>
#include <fstream>

void replaceStr(std::string& str, std::string s1, std::string s2) {
    size_t pos = 0;
    while (true) {
        pos = str.find(s1, pos);
        if (pos == std::string::npos)
            break;
        str = str.substr(0, pos) + s2 + str.substr(pos + s1.length());
        pos += s2.length();
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "ERROR: Invalid parameter" << std::endl;
        return 1;
    }

    std::string infilename(argv[1]);
    std::ifstream infile(infilename.c_str());
    if (!infile.is_open()) {
        std::cout << "ERROR: Cannot open file" << std::endl;
        return 1;
    }
    std::string outfilename(infilename + ".replace");
    std::ofstream outfile(outfilename.c_str());
    if (!outfile.is_open()) {
        std::cout << "ERROR: Cannot open file" << std::endl;
        return 1;
    }

    std::string s1(argv[2]);
    std::string s2(argv[3]);
    if (s1.length() == 0) {
        std::cout << "ERROR: Invalid string" << std::endl;
        return 1;
    }

    std::string str;
    while (getline(infile, str)) {
        replaceStr(str, s1, s2);
        outfile << str;
        if (!infile.eof())
            outfile << std::endl;
    }
    infile.close();
    outfile.close();
}