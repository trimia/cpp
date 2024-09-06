#include "parse.hpp"

Parse::Parse()
{
}

Parse::Parse(Parse const &obj)
{
    this->_map = obj._map;
}

Parse &Parse::operator=(Parse const &obj)
{
    this->_map = obj._map;
    return (*this);
}

Parse::~Parse()
{
}

void Parse::parse(std::string str)
{
    std::string key;
    std::string value;
    size_t pos = 0;
    while ((pos = str.find(":")) != std::string::npos)
    {
        key = str.substr(0, pos);
        str.erase(0, pos + 1);
        pos = str.find(";");
        value = str.substr(0, pos);
        str.erase(0, pos + 1);
        this->_map[key] = value;
    }
}

void Parse::printMap()
{
    for (auto &i : this->_map)
        std::cout << i.first << " : " << i.second << std::endl;
}

std::string Parse::getValue(std::string key)
{
    return this->_map[key];
}

std::string Parse::getKey(std::string value)
{
    for (auto &i : this->_map)
        if (i.second == value)
            return i.first;
    return "Key not found";
}

std::map<std::string, std::string> Parse::getMap()
{
    return this->_map;
}
// open file and parse data
void Parse::parseFile(std::string filename)
{
    std::ifstream
        file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        this->parseCSV(line);
    }
}

//parse data from .csv file formatted: data | exchangerate
void Parse::parseCSV(std::string str)
{
    std::string key;
    std::string value;
    size_t pos = 0;
    while ((pos = str.find("|")) != std::string::npos)
    {
        key = str.substr(0, pos);
        str.erase(0, pos + 1);
        pos = str.find(";");
        value = str.substr(0, pos);
        str.erase(0, pos + 1);
        this->_map[key] = value;
    }
}