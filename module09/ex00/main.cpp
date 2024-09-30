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
    try {
        exchange.openFile(filename);
        exchange.btc();
    } catch (std::exception &e) {
        std::cout << RED << e.what() << NONE << std::endl;
        return 1;
    }
//    exchange.printMap(exchange.get_exchange_rate_db());
//    exchange.printWallet(exchange.get_wallet());

    return 0;
}