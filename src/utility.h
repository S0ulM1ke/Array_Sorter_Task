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

namespace Sort {
    /**
     * @brief Partition function for QuickSort algorithm.
     * @param arr The vector to be partitioned.
     * @param low The starting index of the vector.
     * @param high The ending index of the vector.
     * @tparam T The type of elements in the vector.
     * @return The index of the pivot element after partitioning.
     */
    template<typename T>
    int partition(std::vector<T>& arr, int low, int high) {
        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    /**
     * @brief QuickSort algorithm to sort a vector of integers.
     * @param arr The vector to be sorted.
     * @param low The starting index of the vector.
     * @param high The ending index of the vector.
     * @tparam T The type of elements in the vector.
     */
    template<typename T>
    void quickSort(std::vector<T>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
} // namespace Sort