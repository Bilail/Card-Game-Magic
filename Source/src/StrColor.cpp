//
// Created by Rayane on 05/01/2022.
//

#include "../header/StrColor.h"

std::string StrColor::print(std::string str, std::string color) {
    if (color == "red")
        return "\033[1;31m" + str + "\033[0m";
    else if (color == "green")
        return "\033[1;32m" + str + "\033[0m";
    else if (color == "yellow")
        return "\033[1;33m" + str + "\033[0m";
    else if (color == "blue")
        return "\033[1;34m" + str + "\033[0m";
    else if (color == "magenta")
        return "\033[1;35m" + str + "\033[0m";
    else if (color == "cyan")
        return "\033[1;36m" + str + "\033[0m";
    else if (color == "black")
        return "\033[1;30m" + str + "\033[0m";
    else
        return "\033[1;37m" + str + "\033[0m";
}

std::string StrColor::black(std::string str) {
    return "\033[1;30m" + str + "\033[0m";
}
std::string StrColor::white(std::string str) {
    return "\033[1;37m" + str + "\033[0m";
}
std::string StrColor::red(std::string str) {
    return "\033[1;31m" + str + "\033[0m";
}
std::string StrColor::green(std::string str) {
    return "\033[1;32m" + str + "\033[0m";
}
std::string StrColor::yellow(std::string str) {
    return "\033[1;33m" + str + "\033[0m";
}
std::string StrColor::blue(std::string str) {
    return "\033[1;34m" + str + "\033[0m";
}
std::string StrColor::magenta(std::string str) {
    return "\033[1;35m" + str + "\033[0m";
}
std::string StrColor::cyan(std::string str) {
    return "\033[1;36m" + str + "\033[0m";
}
