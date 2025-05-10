#include "commandlineparser.h"
#include "fileparser.h"
#include "arraybase.h"

#include <iostream>

void printHelp() {
    std::cout << "Usage:\n"
              << "  ArraySorterTask -target <path_to_file> [options]\n\n"
              << "Options:\n"
              << "  -target <file> (required)     Path to input text file to be sorted\n"
              << "  If no options are provided, all operations will be performed.\n\n"
              << "  -print                        Print input arrays\n"
              << "  -sort                         Print sorted arrays\n"
              << "  -intersect                    Print intersection of arrays\n"
              << "  -unique-rev                   Print unique elements in reverse order\n"
              << "  -help                         Show this help message\n";
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv + 1, argv + argc);
    Options opts = parseArguments(args);

    if (!opts.valid) {
        std::cerr << "Error: " << opts.errorMessage << "\n\n";
        printHelp();
        return 1;
    }

    if (opts.help) {
        std::cout << "Help requested.\n\n";
        printHelp();
        return 0;
    }

    // Read integers from the specified file
    auto numbers = FileParser::readIntegersFromFile(opts.targetFile);
    if (numbers.empty()) {
        std::cerr << "Error: No valid data found in the file.\n";
        return 1;
    }

    PlainArray<int> array(numbers);
    array.print(); // Print the original arrays
    

//     for (const auto& line : numbers) {
//         for (const auto& num : line) {
//             std::cout << num << " ";
//         }
//         std::cout << "\n";
//     }

    return 0;
}