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
    static std::string req_select_older_than();
    static std::string req_select_smaller_than();
    static std::string req_select_oldest_owner();
    static std::string req_select_smallest_owner();
    static std::string req_select_auto_by_name();
    static std::string req_select_count_auto_by_name();

    static constexpr std::pair<std::string (*)(), int> vec_func[] = {
        std::pair{req_select_oldest_owner, 0},
        std::pair{req_select_smallest_owner, 0},
        std::pair{req_select_older_than, 0},
        std::pair{req_select_smaller_than, 0},
        std::pair{req_select_auto_by_name, 0},
        std::pair{req_select_count_auto_by_name, 0}
    };

    static constexpr const char* vec_strs_names[]  = {
        "get the smallest owner",
        "get the oldest owner",
        "get owners older than given age",
        "get owners younger than given age",
        "get all cars by name",
        "get count all cars by name"
    };
};

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
    return "SELECT address_id, full_name, date_of_birth FROM t_owner ORDER BY address_id";
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


std::string table_owner::req_select_older_than() {  
    int age;
    std::cout << "enter age >";
    std::cin >> age;
    std::string req  = "SELECT address_id, full_name FROM t_owner WHERE date_of_birth < now() - interval '" +std::to_string(age) + " years' ORDER BY date_of_birth DESC";
    return req;
}

std::string table_owner::req_select_smaller_than() {  
    int age;
    std::cout << "enter age >";
    std::cin >> age;
    std::string req  = "SELECT address_id, full_name FROM t_owner WHERE date_of_birth > now() - interval '" +std::to_string(age) + " years' ORDER BY date_of_birth ASC";
    return req;
}

std::string table_owner::req_select_oldest_owner() {
    return std::string("SELECT address_id, full_name FROM t_owner WHERE date_of_birth = (SELECT MAX(date_of_birth) FROM t_owner)");
}  


std::string table_owner::req_select_smallest_owner() {
    return std::string("SELECT address_id, full_name FROM t_owner WHERE date_of_birth = (SELECT MIN(date_of_birth) FROM t_owner)");
}  

std::string table_owner::req_select_auto_by_name() {
    std::string name;
    std::cout << "enter owner name >";
    std::cin >> name;
    std::string req = "WITH t AS(SELECT reg_id, brand, type_auto, full_name FROM t_auto INNER JOIN t_owner "
        "ON t_owner.address_id = t_auto.address_own) SELECT * FROM t WHERE full_name = '"+ name  + "'";
        return req;
}

std::string table_owner::req_select_count_auto_by_name() {
    std::string name;
    std::cout << "enter owner name >";
    std::cin >> name;
    std::string req = "WITH t AS(SELECT reg_id, brand, type_auto, full_name FROM t_auto INNER JOIN t_owner "
        "ON t_owner.address_id = t_auto.address_own) SELECT COUNT(*) AS count_cars FROM t WHERE full_name = '"+ name  + "'";
        return req;
    }



#endif