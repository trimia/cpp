#include "BitcoinExchange.hpp"
#include "include.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout<<RED << "Usage: ./btc [filename]"<<NONE << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::cout<<filename<<std::endl;
    // Parse parse;
    // parse.parseFile(filename);
    // parse.printMap();
    BitcoinExchange exchange;
    exchange.openFile(filename);
    exchange.printMap(exchange.get_exanche_rate_db());
    exchange.printMap(exchange.get_wallet());
    return 0;
}