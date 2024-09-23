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

bool BitcoinExchange::openFile(std::string filename)
{
    std::string shrinker;
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout<< "Error: Could not open file" << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(file, line))
    {
        if(filename.find("csv") != std::string::npos)
            shrinker = ",";
        else
            shrinker = "|";
        if(line.find("date") != std::string::npos)
            continue;
        try {
            parseFile(line, shrinker);
        } catch (std::exception &e) {
            std::cout <<RED<< e.what()<<NONE << std::endl;
        }
    }
    return true;

}

void BitcoinExchange::parseFile(std::string str, std::string shrinker)
{
    std::string key;
    std::string value;
    size_t pos = 0;
    if(str.find(shrinker) == std::string::npos)
        throw std::invalid_argument("Invalid file format no separator found (data | value)");
    while ((pos = str.find(shrinker)) != std::string::npos)
    {
        key = str.substr(0, pos);
        str.erase(0, pos + 1);
        pos = str.length();
        value = str.substr(0, pos);
        std::istringstream val(value);
        double dvalue;
        val >> dvalue;
        str.erase(0, pos + 1);
        if(shrinker==",")
            this->_exancheRateDb[key] = dvalue;
        else {

            try {
                fillWallet(key, dvalue);
            } catch (std::exception &e) {
                std::cout <<RED<< e.what() <<NONE<< std::endl;
            }
        }
    }
}
static bool isLeapYear(unsigned short year){
    return ((!(year%4) && (year%100)) || !(year%400));
}

static bool validDate(unsigned short year,unsigned short month,unsigned short day){
    unsigned short monthlen[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (!year || !month || !day || month>12)
        return false;
    if (isLeapYear(year) && month==2)
        monthlen[1]++;
    if (day>monthlen[month-1])
        return false;
    return true;
}

static bool isValidDateFormat(const std::string& date) {
    if (date.length() < 11)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.length()-1; ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i]))
            return false;
    }
    struct tm tm;
    memset(&tm, 0, sizeof(tm));
    strptime(date.c_str(), "%Y-%m-%d", &tm);
    if(!validDate(tm.tm_year +1900, tm.tm_mon +1, tm.tm_mday))
        return false;
    return true;
}

void BitcoinExchange::fillWallet(std::string key, double value)
{
    try
    {
        if (!isValidDateFormat(key)){
            throw std::invalid_argument("Invalid date in file.txt the format is YYYY-MM-DD");
        }
        if(value > 1000 || value < 0){
            throw std::invalid_argument("Invalid value in file.txt the value must be less than 1000 and greater than 0");
        }
        this->_wallet.insert(std::pair<std::string, double>(key, value));
    }
    catch (std::exception &e)
    {
        std::cout <<RED<< e.what() << NONE<<std::endl;
    }
}


static std::pair<std::string, double> findNearestDate(const std::map<std::string, double>& exancheRateDb, const std::string& targetDate) {
    struct tm targetTm = {};
    memset(&targetTm, 0, sizeof(targetTm));
    strptime(targetDate.c_str(), "%Y-%m-%d", &targetTm);
    time_t targetTime = mktime(&targetTm);

    std::string nearestDate;
    double nearestValue = 0.0;
    double minDiff = std::numeric_limits<double>::max();

    for(std::_Rb_tree_const_iterator<std::pair<const std::string, double> > it = exancheRateDb.begin(); it != exancheRateDb.end(); ++it)
    {
        struct tm entryTm = {};
        memset(&entryTm, 0, sizeof(entryTm));
        strptime(it->first.c_str(), "%Y-%m-%d", &entryTm);
        time_t entryTime = mktime(&entryTm);
        if (entryTime <= targetTime) {
            double diff = std::difftime(targetTime, entryTime);
            if (diff < minDiff && diff > 0) {
                minDiff = diff;
                nearestDate = it->first;
                nearestValue = it->second;
            }
        }
    }
    return std::make_pair(nearestDate, nearestValue);
}

void BitcoinExchange::btc()
{
    for(std::multimap<std::string, double>::iterator it = _wallet.begin(); it != _wallet.end(); ++it)
            std::cout<<std::left<<std::setw(12)<<it->first<<" => "<<std::setw(4)<<it->second<<std::setw(4)<<" = "<<std::right<<std::setw(4)<<it->second * findNearestDate(_exancheRateDb,it->first).second <<std::endl;
}



void BitcoinExchange::printMap(std::map<std::string, double > map)
{
    for (std::map<std::string, double>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}
void BitcoinExchange::printWallet(std::multimap<std::string, double> map)
{
    for (std::map<std::string, double>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

std::map<std::string, double> BitcoinExchange::get_exchange_rate_db() const
{
    return _exancheRateDb;
}

void BitcoinExchange::set_exchange_rate_db(const std::map<std::string, double>& exanche_rate_db)
{
    _exancheRateDb = exanche_rate_db;
}

std::multimap<std::string, double> BitcoinExchange::get_wallet() const
{
    return _wallet;
}

void BitcoinExchange::set_wallet(const std::multimap<std::string, double>& wallet)
{
    _wallet = wallet;
}
