#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    std::string word;
    int count = 0;
    if(argc < 2) {
        std::cerr << "USAGE: ./countWords <filepath>" << std::endl;
        return EXIT_FAILURE;
    }
    std::ifstream infile(argv[1]);
    while(infile >> word) {
        count ++;
    }
    std::cout << "Total: " << count << " words!" << std::endl;
    return 0;
}
