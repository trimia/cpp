#ifndef  PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <string>
#include <map>

class Parse
{
private:
    std::map<std::string, std::string> _map;
public:
    Parse();
    Parse(Parse const &obj);
    Parse &operator=(Parse const &obj);
    ~Parse();
    void parse(std::string str);
    void printMap();
    std::string getValue(std::string key);
    std::string getKey(std::string value);
    std::map<std::string, std::string> getMap();
};

#endif