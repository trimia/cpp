#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc [filename]" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::cout<<filename<<std::endl;
    Parse parse;
    parse.parseFile(filename);
    parse.printMap();

}