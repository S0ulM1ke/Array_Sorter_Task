#include "commandlineparser.h"
#include "fileparser.h"
#include "arraytransformer.h"
#include "sortedarray.h"
#include "intersectarray.h"
#include "uniquerevarray.h"

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

    if (opts.print) {
        // Print the original arrays
        PlainArray<int> array(numbers);
        array.print();
    }

    if (opts.sort) {
        // Sort the arrays and print them
        SortedArray<int> sortedArray(numbers);
        sortedArray.transform();
        sortedArray.print();
    }

    if (opts.intersect) {
        // Find the intersection of the arrays and print it
        IntersectArray<int> intersectArray(numbers);
        intersectArray.transform();
        intersectArray.print();
    }

    if (opts.uniqueReverse) {
        // Find unique elements in reverse order and print them
        UniqueReverseArray<int> uniqueRevArray(numbers);
        uniqueRevArray.transform();
        uniqueRevArray.print();
    }

    return 0;
}