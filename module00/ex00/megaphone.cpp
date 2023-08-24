
#include <iostream>

int main(int argc, char **argv) {
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        for (int i = 1; i < argc; i++) {
            std::string ar(argv[i]);
            for (unsigned long j = 0; j < ar.size(); j++) {
                std::cout << (char) toupper(ar[j]);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
