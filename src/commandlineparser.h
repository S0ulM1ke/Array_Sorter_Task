// commandlineparser.h
#pragma once
#include <string>
#include <vector>

struct Options {
    std::string targetFile;
    bool print = false;
    bool sort = false;
    bool intersect = false;
    bool uniqueReverse = false;
    bool help = false;
    bool valid = true;
    std::string errorMessage;
};

Options parseArguments(const std::vector<std::string>& args);
