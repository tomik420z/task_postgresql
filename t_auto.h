#pragma once 
#ifndef T_AUTO_H
#define T_AUTO_H
#include "string_conv/str_conv.h"
#include <iostream>
#include <vector>

class table_auto{
public:
    using arr_additional_func = std::vector<std::pair<std::string (*)(), int>>;
protected:
    static std::string __input_reg_id();
    static std::string __input_brand();
    static std::string __input_type_auto();
    static int __input_address_own();
    static int __input_route_number();
public: 

    table_auto() = default;
    ~table_auto() = default;

    static std::string req_show();
    static std::string req_select();
    static std::string req_update();
    static std::string req_insert();
    static std::string req_delete_id();

    static const std::vector<std::string> vec_strs_names;
    static const arr_additional_func vec_func;
};

const std::vector<std::string> table_auto::vec_strs_names{};

const table_auto::arr_additional_func table_auto::vec_func{};


std::string table_auto::__input_reg_id() {
    std::string reg_id;
    std::cout << "enter 'reg_id' >";
    __ignore_spaces();
    std::getline(std::cin ,reg_id);
    return reg_id;
}

std::string table_auto::__input_brand() {
    std::string brand;
    std::cout << "enter 'brand' >";
    __ignore_spaces();
    std::getline(std::cin ,brand);
    return brand;
}

std::string table_auto::__input_type_auto() {
    std::string type_auto;
    std::cout << "enter 'type_auto' >";
    __ignore_spaces();
    std::getline(std::cin ,type_auto);
    return type_auto;
}

int table_auto::__input_address_own() {
    int address_own;
    std::cout << "enter 'address_own' >";
    std::cin >> address_own;
    return address_own;
}

int table_auto::__input_route_number() {
    int route_number;
    std::cout << "enter 'route_number' >";
    std::cin >> route_number;
    return route_number;
}

std::string table_auto::req_show() {
    return "SELECT reg_id, brand, type_auto, address_own, route_number FROM t_auto ORDER BY reg_id";
}

std::string table_auto::req_select() {
    std::string reg_id = __input_reg_id();
    std::string req = "SELECT reg_id, brand, type_auto FROM t_auto WHERE reg_id = '" + reg_id + "'";
    std::cout <<  req << std::endl;
    return req.c_str();
}

std::string table_auto::req_update() {
    std::string reg_id = __input_reg_id();
    std::string brand = __input_brand();
    std::string type_auto = __input_type_auto();
    int address_own = __input_address_own();
    int route_number = __input_route_number();
    std::string req = "UPDATE t_auto SET brand = '" + brand + "', type_auto = '" + type_auto  + "',  address_own = " + std::to_string(address_own) + ", route_number = " + std::to_string(route_number) + 
        " WHERE reg_id = '" + reg_id + "'";
    std::cout << req << std::endl;
    return req.c_str();
}

std::string table_auto::req_insert() {
    std::string reg_id = __input_reg_id();
    std::string brand = __input_brand();
    std::string type_auto = __input_type_auto();
    int address_own = __input_address_own();
    int route_number = __input_route_number();
    std::string req = "INSERT INTO t_auto(reg_id, brand, type_auto, address_own, route_number) VALUES('" 
                        + reg_id + "', '" + brand + "' , '" + type_auto  + "', " 
                            + std::to_string(address_own)  + ", " + std::to_string(route_number) + ")";
    std::cout << req << std::endl;
    return req.c_str();
}

std::string table_auto::req_delete_id() {
    std::string reg_id = __input_reg_id();
    std::string req = "DELETE FROM t_auto WHERE reg_id = '" + reg_id +  "'";
    std::cout << req << std::endl;
    return req.c_str();
}

#endif