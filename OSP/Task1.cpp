#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>


void TaskFilter(std::string infile, std::string outfile) {
    std::cout << "Reading input file and creating output file" << std::endl;
    std::string nextword; 
    std::vector<std::string> wvector;
    std::ifstream istream(infile);
    std::ofstream ostream(outfile);

    std::cout << "Starting filtering of words with punctuation and words above length of 15 and below 3..." << std::endl;
    while (istream >> nextword) {
        if (ispunct(nextword[0])) {
            nextword.erase();
        }
        else {
            for (int i = 0, length = nextword.size(); i < length; i++) {
                if (ispunct(nextword[i]) || nextword[i] == '\'') {
                    nextword.erase(i--, 1);
                    length = nextword.size();
                }
            }
            if (nextword.size() > 2 && nextword.size() < 16) {
                wvector.push_back(nextword);
            }
        }  
    }

    std::cout << "Sorting vector..." << std::endl;
    wvector.erase(std::unique( wvector.begin(), wvector.end() ), wvector.end() );

    std::cout << "Writing to output file..." << std::endl;

    for (std::string nextword: wvector) {
        ostream << nextword << std::endl;
    }
}


int main (int argc, char* argv[]) {

    std::string in = argv[1];
    std::string out = argv[2];

    TaskFilter(in, out);    

    return EXIT_SUCCESS;

}