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
    printHelp();
    return 0;
}