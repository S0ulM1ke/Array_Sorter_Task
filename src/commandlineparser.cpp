#include "commandlineparser.h"

Options parseArguments(const std::vector<std::string> &args)
{
    Options opts;

    for (size_t i = 0; i < args.size(); ++i) {
        const std::string& arg = args[i];

        if (arg == "-help") {
            opts.help = true;
            return opts;
        } else if (arg == "-target") {
            if (i + 1 < args.size()) {
                opts.targetFile = args[++i];
            } else {
                opts.valid = false;
                opts.errorMessage = "Missing file path after -target";
                return opts;
            }
        } else if (arg == "-print") {
            opts.print = true;
        } else if (arg == "-sort") {
            opts.sort = true;
        } else if (arg == "-intersect") {
            opts.intersect = true;
        } else if (arg == "-unique-rev") {
            opts.uniqueReverse = true;
        } else {
            opts.valid = false;
            opts.errorMessage = "Unknown argument: " + arg;
            return opts;
        }
    }

    if (!opts.help && opts.targetFile.empty()) {
        opts.valid = false;
        opts.errorMessage = "Missing required argument: -target <file>";
    }else if (!opts.help &&
        !opts.sort && !opts.intersect && !opts.uniqueReverse && !opts.print) {
            // Enable all modes by default if none specified
            opts.sort = true;
            opts.intersect = true;
            opts.uniqueReverse = true;
            opts.print = true;
        }

    return opts;
}