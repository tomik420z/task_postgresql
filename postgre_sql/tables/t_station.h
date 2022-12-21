#pragma once 
#ifndef T_STATION_H
#define T_STATION_H
#include "string_conv/str_conv.h"
#include <iostream>
#include <vector>
#include <array>

class table_station {
public:
    using arr_additional_func = std::vector<std::pair<std::string (*)(), int>>;
    // columns: title_id, address_id, type_stations
protected:
    static std::string __input_title_id();
    static int __input_rating();
    static bool __input_type();

public:
    table_station() = default;
    ~table_station() = default;

    static std::string req_show();
    static std::string req_select();
    static std::string req_update();
    static std::string req_insert();
    static std::string req_delete_id();
    static std::string req_select_max_rating();
    static std::string req_select_min_rating();
    static std::string req_select_interval_rating();
    static std::string req_select_rating_more_then();
    
    static constexpr std::pair<std::string (*)(), int> vec_func[] = {std::pair{table_station::req_select_max_rating, 0},
                                                                    std::pair{table_station::req_select_min_rating, 0}, 
                                                                    std::pair{table_station::req_select_interval_rating, 0}, 
                                                                    std::pair{table_station::req_select_rating_more_then, 0}
                                                                    };

    static constexpr const char* vec_strs_names[]  = {"give the station with the highest rating", 
                                                        "give the station with the lowest rating",
                                                        "get stations matching the interval",
                                                        "get stations with higher rating then value"};
};


std::string table_station::__input_title_id() {
    std::string title_id;
    std::cout << "enter 'title_id' >";
    __ignore_spaces();
    std::getline(std::cin, title_id);
    return title_id;
}


int table_station::__input_rating() {
    int type_st;
    std::cout << "enter 'rating' >"; 
    std::cin >> type_st;
    return type_st;
}

bool table_station::__input_type() {
    bool type_station;
    std::cout << "enter 'type_station' >"; 
    std::cin >> type_station;
    return type_station;
}
 

std::string table_station::req_show() {
    return std::string("SELECT title_id, rating, type_station FROM t_stop ORDER BY title_id");
}

std::string table_station::req_select() {
    std::string id = __input_title_id();
    std::string req = "SELECT title_id, rating, type_station FROM t_stop WHERE title_id = '" + id + "';";
    std::cout << req << std::endl;
    return req;
}

std::string table_station::req_update() {
    std::string title_id = __input_title_id();
    int rating = __input_rating();
    bool type_st = __input_type();
    std::string req = "UPDATE t_stop SET rating = " + std::to_string(rating) + 
                    " , type_station = " +  convert_bool(type_st) +  
                    " WHERE title_id = '" + title_id + "'";
    std::cout << req << std::endl;
    return req;
}

std::string table_station::req_insert() {
    std::string title_id = __input_title_id();
    int rating = __input_rating();
    bool type_st = __input_type();

    std::string req = "INSERT INTO t_stop(title_id, rating, type_station) VALUES('" +   
                title_id + "', " + std::to_string(rating) + ", " + 
                    convert_bool(type_st) + ");";

    std::cout << req << std::endl;
    return req;
}

std::string table_station::req_delete_id() {
    std::string title_id = __input_title_id();
    std::string req = "DELETE FROM t_stop WHERE title_id = '" + 
                            title_id + "';";
    std::cout << req << std::endl;
    return req;
}

std::string table_station::req_select_max_rating() {
    return std::string("SELECT title_id, rating, type_station FROM t_stop WHERE rating = (SELECT MAX(rating) FROM t_stop)");
}

std::string table_station::req_select_min_rating() {
    return std::string("SELECT title_id, rating, type_station FROM t_stop WHERE rating = (SELECT MIN(rating) FROM t_stop)");
}

std::string table_station::req_select_interval_rating() {
    int min, max;
    std::cout << "enter interval limits:" << std::endl;
    std::cout << "enter left border >";
    std::cin >> min;
    std::cout << "enter right border >";
    std::cin >> max;
    std::string req = "SELECT title_id, rating, type_station FROM t_stop WHERE rating BETWEEN " + std::to_string(min) + " AND " + std::to_string(max);
    return req;
}

std::string table_station::req_select_rating_more_then() {
    int min;
    std::cout << "enter min rating >";
    std::cin >> min;
    std::string req = "SELECT * FROM t_stop WHERE rating > " + std::to_string(min);
    return req;
}

#endif