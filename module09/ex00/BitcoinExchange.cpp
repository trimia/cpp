#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    try
    {
        openFile("data.csv");
    }
    catch (...)
    {
        std::cout << "Error: Could not open csv file are you sure is in the root of the project?" << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj)
{
    this->_exancheRateDb = obj._exancheRateDb;
    this->_wallet = obj._wallet;
    return (*this);
}

void BitcoinExchange::openFile(std::string filename)
{
    std::cout << "Opening file: " << filename << std::endl;
    std::string shrinker="";
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout<< "Error: Could not open file" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        if(filename.find("csv") != std::string::npos)
            shrinker = ",";
        else
            shrinker = "|";
        this->parseFile(line, shrinker);
    }

}

void BitcoinExchange::parseFile(std::string str, std::string shrinker)
{
    static int i = 0;
    if (i==0)
        std::cout << "Parsing file: " << str <<" shrinker " << shrinker << std::endl;
    i++;
    std::string key;
    std::string value;
    size_t pos = 0;
    while ((pos = str.find(shrinker)) != std::string::npos)
    {
        key = str.substr(0, pos);
        str.erase(0, pos + 1);
        pos = str.find(";");
        value = str.substr(0, pos);
        str.erase(0, pos + 1);
        if(shrinker==",")
            this->_exancheRateDb[key] = std::stod(value);
        else
            fillWallet(key, std::stod(value));
    }
}

bool isleapyear(unsigned short year){
    return (!(year%4) && (year%100) || !(year%400));
}

//1 valid, 0 invalid
bool valid_date(unsigned short year,unsigned short month,unsigned short day){
    unsigned short monthlen[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (!year || !month || !day || month>12)
        return 0;
    if (isleapyear(year) && month==2)
        monthlen[1]++;
    if (day>monthlen[month-1])
        return 0;
    return 1;
}

void BitcoinExchange::fillWallet(std::string key, double value)
{
    std::cout << "Filling wallet: " << key << " : " << value << std::endl;
    struct tm tm;
    try
    {
        if (strptime(key.c_str(), "%Y-%m-%d", &tm))
            throw std::invalid_argument("Invalid date in file.txt the format is YYYY-MM-DD");
        if(value < 1000 && value>0)
            throw std::invalid_argument("Invalid value in file.txt the value must be less than 1000 and greater than 0");
        this->_wallet[key] = value;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void BitcoinExchange::printMap(std::map<std::string, double > map)
{
    for (std::map<std::string, double>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

std::map<std::string, double> BitcoinExchange::get_exanche_rate_db() const
{
    return _exancheRateDb;
}

void BitcoinExchange::set_exanche_rate_db(const std::map<std::string, double>& exanche_rate_db)
{
    _exancheRateDb = exanche_rate_db;
}

std::map<std::string, double> BitcoinExchange::get_wallet() const
{
    return _wallet;
}

void BitcoinExchange::set_wallet(const std::map<std::string, double>& wallet)
{
    _wallet = wallet;
}
