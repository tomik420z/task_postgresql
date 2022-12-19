#pragma once 
#ifndef T_OWNER_H
#define T_OWNER_H
#include "string_conv/str_conv.h"
#include <iostream>
#include <vector>

class table_owner {
public:
    using arr_additional_func = std::vector<std::pair<std::string (*)(), int>>;
protected:
    static int __input_address_id();
    static std::string __input_full_name();
    static std::string __input_date_of_birth();
    
public:
    table_owner() = default;
    ~table_owner() = default;

    static std::string req_show();
    static std::string req_select();
    static std::string req_update();
    static std::string req_insert();
    static std::string req_delete_id();

    static const std::vector<std::string> vec_strs_names;
    static const arr_additional_func vec_func;
};

const std::vector<std::string> table_owner::vec_strs_names{};

const table_owner::arr_additional_func table_owner::vec_func{};

int table_owner::__input_address_id() {
    int id;
    std::cout << "enter 'address_id' >";
    std::cin >> id;
    return id;
}

std::string table_owner::__input_full_name() {
    std::string full_name;
    std::cout << "enter 'full_name' >";
    __ignore_spaces();
    std::getline(std::cin, full_name);
    return full_name;
}

std::string table_owner::__input_date_of_birth(){
    std::string date_of_birth;
    std::cout << "enter 'date_if_birth' >";
    __ignore_spaces();
    std::getline(std::cin, date_of_birth);
    return date_of_birth;
}

std::string table_owner::req_show() {
    return "SELECT address_id, full_name, date_of_birth FROM t_owner";
}

std::string table_owner::req_select() {
    int id = __input_address_id();
    std::string req = "SELECT address_id, full_name, date_of_birth WHERE t_owner WHERE address_id = "
         +  std::to_string(id); 
    std::cout << req << std::endl;
    return req;
}   

std::string table_owner::req_update() {
    int id  = __input_address_id();
    std::string full_name = __input_full_name();
    std::string date_of_birth = __input_date_of_birth();
    std::string req = "UPDATE t_owner SET full_name = '" + full_name + "', date_of_birth = '"
     + date_of_birth + "' WHERE address_id = " + std::to_string(id);
    std::cout << req << std::endl;
    return req;  
}

std::string table_owner::req_insert() {
    int id = __input_address_id();
    std::string full_name = __input_full_name();
    std::string date_of_birth = __input_date_of_birth();
    std::string req = "INSERT INTO t_owner(address_id, full_name, date_of_birth) VALUES(" 
        + std::to_string(id) + ", '" + full_name + "', '" 
        + date_of_birth + "')";
    std::cout << req << std::endl;
    return req;   
}

std::string table_owner::req_delete_id() {
    int id = __input_address_id();
    std::string req = "DELETE FROM t_owner WHERE address_id = " + std::to_string(id);
    std::cout << id << std::endl;
    return req;
}

#endif