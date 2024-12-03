#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

int main() {
    std::ifstream inputFile("day3.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file" << std::endl;
        return 1;
    }

    std::ostringstream ss;
    ss << inputFile.rdbuf();
    inputFile.close();
    std::string data = ss.str();

    bool mulEnabled = true; 
    int sum = 0;

    std::regex instructionRegex(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
    std::smatch match;
    std::string::const_iterator searchStart(data.cbegin());

    while (std::regex_search(searchStart, data.cend(), match, instructionRegex)) {
        std::string matched = match.str();

        if (std::regex_match(matched, std::regex(R"(mul\((\d+),(\d+)\))"))) {
            if (mulEnabled) {
                std::smatch mulMatch;
                std::regex_search(matched, mulMatch, std::regex(R"(\((\d+),(\d+)\))"));
                int a = std::stoi(mulMatch[1].str());
                int b = std::stoi(mulMatch[2].str());
                sum += a * b;
            }
        } else if (matched == "do()") {
            mulEnabled = true;
        } else if (matched == "don't()") {
            mulEnabled = false;
        }

        searchStart = match.suffix().first;
    }

    std::cout << sum << std::endl;
    return 0;
}
