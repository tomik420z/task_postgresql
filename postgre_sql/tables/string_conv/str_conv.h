#pragma once 
#ifndef STR_CONV_H
#define STR_CONV_H
#include <iostream>
#include <string>

std::string convert_bool(bool v) {
    return std::string(v ? "true" : "false");
}

void __ignore_spaces() {
        using std::cin;
        while(cin.peek() == ' ') {
            cin.get();
        }
        if (cin.peek() == '\n') {
            cin.ignore();
        }
}

#endif