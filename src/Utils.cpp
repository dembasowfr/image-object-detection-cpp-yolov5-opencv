#include "Utils.h"
#include <fstream>
#include <iostream>

std::vector<std::string> loadClassList(const std::string& filePath) {
    std::vector<std::string> classList;
    std::ifstream ifs(filePath);
    std::string line;
    while (std::getline(ifs, line)) {
        classList.push_back(line);
    }
    ifs.close();
    return classList;
}
