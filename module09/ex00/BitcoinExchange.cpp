#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(double exchangeRate)
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj)
{
    this->_exchangeRate = obj._exchangeRate;
    this->_wallet = obj._wallet;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj)
{
    this->_exchangeRate = obj._exchangeRate;
    this->_wallet = obj._wallet;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::setWallet(std::string name, double amount)
{
    this->_wallet[name] = amount;
}

void BitcoinExchange::setExchangeRate(double exchangeRate)
{
    this->_exchangeRate = exchangeRate;
}

double BitcoinExchange::getWallet(std::string name) const
{
    return this->_wallet.at(name);
}

double BitcoinExchange::getExchangeRate() const
{
    return this->_exchangeRate;
}

void BitcoinExchange::convert(std::string name, double amount)
{
    this->_wallet[name] = amount / this->_exchangeRate;
}

void BitcoinExchange::convert(double amount)
{
    for (auto &i : this->_wallet)
        i.second = amount / this->_exchangeRate;
}

void BitcoinExchange::convert(std::string name)
{
    this->_wallet[name] = this->_wallet[name] / this->_exchangeRate;
}

void BitcoinExchange::convert()
{
    for (auto &i : this->_wallet)
        i.second = i.second / this->_exchangeRate;
}

void BitcoinExchange::printWallet()
{
    for (auto &i : this->_wallet)
        std::cout << i.first << ": " << i.second << std::endl;
}
