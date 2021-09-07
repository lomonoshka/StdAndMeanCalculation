#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <filesystem>
bool is_uinteger(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int main (int argc, char** argv) {
    std::set<uint> print_values;
    bool save = false;
    for (int i = 1; i < argc; ++i) {

        if (std::string(argv[i]) == "save" && i == 1) {
            save = true;
            continue; 
        }
        if (!is_uinteger(argv[i])) {
            std::cerr << "Invalid initial paramers\n";
            return -1;
        }
        print_values.insert(std::stoul(argv[i]));
    }  

    std::ifstream fin("input/variance_calc.tsv");
    std::ofstream fout;
    if (save) {
        if (!std::filesystem::exists("output"))
            std::filesystem::create_directory("output");
        fout.open("output/mean_and_std.tsv");
    }

    std::string line;
    double previous_mean = 0, previous_std = 0;

    int i = 1;
    while (getline(fin, line)) {
        double num = std::stod(line);
        double new_mean = previous_mean + (num - previous_mean) / i;
        if (i > 1)
            previous_std = sqrt(((i - 2) * previous_std * previous_std + (num - new_mean) * (num - previous_mean)) / (i - 1));
        previous_mean = new_mean;
        
        if (save) {
            fout << previous_mean << " " << previous_std << "\n";
        }
        if (print_values.find(i) != print_values.end())
            printf("%d: mean: %f, std: %f\n", i, previous_mean, previous_std);
        ++i;
    }
}