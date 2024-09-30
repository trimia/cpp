#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "include.h"
#include "iostream"
#include "string"
#include "map"
#include <ctime>
#include <sstream>
#include <cstring>
#include <iostream>
#include <map>
#include <ctime>
#include <limits>
#include <iomanip>
#include <fstream>



class BitcoinExchange
{
private:
    std::map<std::string, double>       _exancheRateDb;
    std::multimap<std::string, double>  _wallet;
    bool                                _data_loaded;
public:

    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange &operator=(BitcoinExchange const &obj);
    bool openFile(std::string filename);
    void parseFile(std::string str, std::string shrinker);
    void fillWallet(std::string key, double value);
    void printMap(std::map<std::string, double> map);
    void printWallet(std::multimap<std::string, double> map);
    void btc();

    std::map<std::string, double> get_exchange_rate_db() const;
    void set_exchange_rate_db(const std::map<std::string, double>& exanche_rate_db);
    std::multimap<std::string, double> get_wallet() const;
    void set_wallet(const std::multimap<std::string, double>& wallet);

};
#endif