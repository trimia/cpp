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
    BitcoinExchange exchange;
    exchange.openFile(filename);
//    exchange.printMap(exchange.get_exchange_rate_db());
//    exchange.printWallet(exchange.get_wallet());
    exchange.btc();

    return 0;
}