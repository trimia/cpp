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
    for (std::map<std::string, std::string>::iterator it = this->_map.begin(); it != this->_map.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
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

void ::openFile(std::string filename)
{
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

void ::parseFile(std::string str, std::string shrinker)
{
    std::string key;
    std::string value;
    size_t pos = 0;
    while ((pos = str.find(",")) != std::string::npos)
    {
        key = str.substr(0, pos);
        str.erase(0, pos + 1);
        pos = str.find(";");
        value = str.substr(0, pos);
        str.erase(0, pos + 1);
    this->_map[key] = value;
    }
}