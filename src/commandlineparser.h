/**
 * @file commandlineparser.h
 * @brief Header file for command line argument parsing.
 */
#pragma once
#include <string>
#include <vector>

/**
 * @brief Struct to hold command line options.
 * This struct contains various options that can be set via command line arguments.
 * It includes the target file path, flags for different operations,
 * and a validity check.
 */
struct Options {
    std::string targetFile; // Path to the target file
    bool print = false; // Flag to print input arrays
    bool sort = false; // Flag to sort arrays
    bool intersect = false; // Flag to find intersection of arrays
    bool uniqueReverse = false; // Flag to find unique elements in reverse order
    bool help = false; // Flag to show help message
    bool valid = true; // Flag to check if the options are valid
    std::string errorMessage; // Error message if options are invalid
};

Options parseArguments(const std::vector<std::string>& args);
