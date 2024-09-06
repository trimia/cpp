#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "include.h"
#include "iostream"
#include "string"
#include "map"
#include "ctime"


class BitcoinExchange
{
private:
    std::map<std::string, double> _wallet;
    double _exchangeRate;
public:

    BitcoinExchange();
    BitcoinExchange(double exchangeRate);
    BitcoinExchange(BitcoinExchange const &obj);
    BitcoinExchange &operator=(BitcoinExchange const &obj);
    ~BitcoinExchange();
    void setExchangeRate(double exchangeRate);
    double getWallet(std::string name) const;
    double getExchangeRate() const;
    void convert(std::string name, double amount);
    void convert(double amount);
    void convert(std::string name);
    void convert();
    void printWallet();
    void printExchangeRate();
    void printAll();
    void printAll(std::string name);
    void printAll(double amount);

};
#endif