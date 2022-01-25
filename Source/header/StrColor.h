//
// Created by Rayane on 05/01/2022.
//

#ifndef MAGIC_STRCOLOR_H
#define MAGIC_STRCOLOR_H

#include <string>

class StrColor {
public:
    static std::string print(std::string str, std::string color);
    static std::string black(std::string);
    static std::string white(std::string);
    static std::string red(std::string);
    static std::string green(std::string);
    static std::string yellow(std::string);
    static std::string blue(std::string);
    static std::string magenta(std::string);
    static std::string cyan(std::string);
};

#endif //MAGIC_STRCOLOR_H
