#include "bstd.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string name = "Ho;mer ;Jay ;Sim;pson";

    bstd::strings::replace_all(name, ";", " ", 2);

    for (auto tok : bstd::strings::split(name, ';')){
        std::cout << tok << "\n";
    }

    return 0;
}
