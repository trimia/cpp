//
// Created by Matteo Mariani on 14/08/23.
//
#include "iostream"
#include "fstream"
#include "cstdlib"
#include "string"

#define SHELLSCRIPT "\
#/bin/bash \n\
echo -e \"\" \n\
echo -e \"This is a test shell script inside C code!!\" \n\
read -p \"press <enter> to continue\" \n\
clear\
"

int error(std::string str) {
    std::cout << "Error : " << str << std::endl;
    return -1;
}

int main(int argc, char **argv) {
    FILE *fd;
    int i = 0;
    if (argc != 4) {
        std::cout << argc << std::endl;
        error("too much arguments");
    }
    std::string s2 = argv[3];
    std::string s1 = argv[2];
    std::string filename = argv[1];
    //.isopen()
    if ((fd = fopen(argv[1], "r")) == NULL) {
        return error("file not found");
    }

    std::ifstream source(argv[1], std::ios::binary);
    std::string replace = ".replace";
    std::ofstream dest(filename + replace, std::ios::binary);

    source.seekg(0, std::ios::end);
    std::ifstream::pos_type size = source.tellg();
    source.seekg(0);
    // allocate memory for buffer
    char *buffer = new char[size];

    // copy file
    source.read(buffer, size);
    std::string appog;
    appog.append(buffer);
    int flag = -1;
    while ((i = appog.find(argv[2])) != (int) std::string::npos) {
        appog.resize(appog.size() + s2.size());
        appog.insert(i, s2);
        appog.erase(i + s2.size(), s1.size());
        flag = 0;
    }
    if (flag == -1)
        return error("s2 string is not in the file");
    dest.write(appog.c_str(), size);

    // clean up
    delete[] buffer;
    source.close();
    dest.close();
    std::system("echo \"\033[38;5;46m auto test result \033[0m\"");
    std::string str = "diff ";
    str.append(filename + " " + filename + replace+"| grep pippo |wc -l; diff ");
    str.append(filename + " " + filename + replace+"| grep pippa|wc -l");
    std::cout<<str<<std::endl;
//    "diff filename filename.replace | grep pippo ;  grep pippo"

    std::system(str.c_str());

    return 0;


}
