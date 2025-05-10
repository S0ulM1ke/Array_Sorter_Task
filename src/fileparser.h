#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

// The FileParser namespace contains functions for parsing text files
// and converting their contents into structured data formats like vectors.
namespace FileParser {

    // Function to parse a line of text into a vector of integers
    std::vector<int> parseLineToIntegers(const std::string& line) {
        std::vector<int> result;
        std::string cleaned = line;
        
        // Remove any non-digit characters except for spaces and commas
        std::replace(cleaned.begin(), cleaned.end(), ',', ' ');
    
        std::istringstream iss(cleaned);
        int number;
        while (iss >> number) {
            result.push_back(number);
        }
    
        return result;
    }

    // Function to read integers from a file and store them in a vector
    std::vector<std::vector<int>> readIntegersFromFile(const std::string& filename) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Error: Could not open file: " << filename << '\n';
            return {}; // Return an empty vector
        }

        std::string line;
        std::vector<std::vector<int>> numbers;
        int lineNumber = 1; // For error messages
        while (std::getline(file, line)) {
            if (line.empty()) continue; // Skip empty lines

            try {
                auto parsed = parseLineToIntegers(line);
                numbers.push_back(parsed);
            } catch (const std::exception& e) {
                std::cerr << "Error parsing line " << lineNumber << ": " << e.what() << '\n';
                continue; // Skip this line and continue with the next one
            }
            ++lineNumber;
        }

        return numbers;
    }
} // namespace FileParser