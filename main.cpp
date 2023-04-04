#include <argparse/argparse.hpp>
#include <cdfpp/cdf.hpp>
#include <fmt/core.h>
#include <iostream>
#include <list>
#include <string>
#include <thread>
#include <vector>

void show_file(const std::string& file)
{
    if (auto maybe_cdf = cdf::io::load(file); maybe_cdf) {
        const auto cdf = *maybe_cdf;
        std::cout << file << ":\n"
                  << cdf << "\n";
    }
}

int main(int argc, char* argv[])
{
    argparse::ArgumentParser program("cdf_ori_readall");

    program.add_argument("--files")
        .help("input files")
        .nargs(argparse::nargs_pattern::any)
        .required();

    try {
        program.parse_args(argc, argv);
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        return 1;
    }

    auto files = program.get<std::vector<std::string>>("--files");

    for (const auto& file : files) {
        show_file(file);
    }

    return 0;
}
