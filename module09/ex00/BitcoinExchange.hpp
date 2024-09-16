#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "include.h"
#include "parse.hpp"
#include "iostream"
#include "string"
#include "map"
#include "ctime"
#include <sstream>


class BitcoinExchange
{
private:
    std::map<std::string, double> _exancheRateDb;
    std::map<std::string, double> _wallet;
public:

    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange &operator=(BitcoinExchange const &obj);
    bool openFile(std::string filename);
    void parseFile(std::string str, std::string shrinker);
    void fillWallet(std::string key, double value);
    void printMap(std::map<std::string, double> map);

    std::map<std::string, double> get_exanche_rate_db() const;
    void set_exanche_rate_db(const std::map<std::string, double>& exanche_rate_db);
    std::map<std::string, double> get_wallet() const;
    void set_wallet(const std::map<std::string, double>& wallet);
};
#endif