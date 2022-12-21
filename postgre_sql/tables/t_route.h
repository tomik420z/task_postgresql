#pragma once 
#ifndef T_ROUTE_H
#define T_ROUTE_H
#include "string_conv/str_conv.h"
#include <iostream>
#include <vector>


class table_route {
public:
    using arr_additional_func = std::vector<std::pair<std::string (*)(), int>>;
    // route_id : auto, shipping_address, arrival_address, distance
protected: 
    static int __input_id();
    static std::string __input_sihpping_address();
    static std::string __input_arrival_address();
    static int __input_distance();

public:
    table_route() = default;
    ~table_route() = default;

    static std::string req_show();
    static std::string req_select();
    static std::string req_update();
    static std::string req_insert();
    static std::string req_delete_id();
    static std::string req_select_max_distance();
    static std::string req_select_min_distance();
    static std::string req_select_numbers_of_route_passin_station();
    static std::string req_select_auto_passing_station();

    static constexpr std::pair<std::string (*)(), int> vec_func[] = { std::pair{req_select_max_distance, 0},
                                                                        std::pair{req_select_min_distance, 0},
                                                                        std::pair{req_select_numbers_of_route_passin_station, 0},
                                                                        std::pair{req_select_auto_passing_station, 0}
                                                                    };

    static constexpr const char* vec_strs_names[]  = {"give the route with the highest distance", 
                                                    "give the route with the lowes distance",
                                                    "get the numbers of routes passing through the station",
                                                    "get cars passing through the station"
                                                    };

};

int table_route::__input_id() {
    int id;
    std::cout << "enter 'id' >";
    std::cin >> id;
    return id;
}

std::string table_route::__input_sihpping_address() {
    std::string shipping_adress;
    std::cout << "enter 'shipping_adress' >";
    __ignore_spaces();
    std::getline(std::cin, shipping_adress);
    return shipping_adress;
}

std::string table_route::__input_arrival_address() {
    std::string arrival_address;
    std::cout << "enter 'arrival_adress' >";
    __ignore_spaces();
    std::getline(std::cin, arrival_address);
    return arrival_address;

}
int table_route::__input_distance() {
    int dist;
    std::cout << "enter 'distance' >";
    std::cin >> dist;
    return dist;
}

std::string table_route::req_show() {
    return std::string("SELECT route_id, shipping_address, arrival_address, distance FROM t_route ORDER BY route_id");
}
std::string table_route::req_select() {
    int id = __input_id();
    std::string req =  "SELECT route_id, shipping_address, arrival_address, distance FROM t_route WHERE route_id = "
        + std::to_string(id); 
    std::cout << req << std::endl;
    return req;
}
std::string table_route::req_update() {
    int id = __input_id();
    std::string shipping_adress = __input_sihpping_address();
    std::string arrival_adress = __input_arrival_address();
    int distance = __input_distance();
    std::string req = "UPDATE t_route SET shipping_address = '" + shipping_adress + 
    "', arrival_address = '" + arrival_adress +
    + "', distance = " + std::to_string(distance) +  
          " WHERE route_id = " 
        + std::to_string(id);
    std::cout << req << std::endl;
    return req;
}

std::string table_route::req_insert() {
    std::string shipping_adress = __input_sihpping_address();
    std::string arrival_adress = __input_arrival_address();
    int distance = __input_distance();
    std::string req = "INSERT INTO t_route (shipping_address, arrival_address, distance) VALUES('" 
        + shipping_adress 
        + "', '"  + arrival_adress 
        + "', " + std::to_string(distance) + ")"; 

    std::cout << req << std::endl;
    return req;
}

std::string table_route::req_delete_id() {
    int id = __input_id();
    std::string req = "DELETE FROM t_route WHERE route_id = " 
        + std::to_string(id);
    std::cout << req.c_str() << std::endl;
    return req;  
}

std::string table_route::req_select_max_distance() {
    return std::string("SELECT route_id, shipping_address, arrival_address, distance FROM t_route WHERE distance = (SELECT MAX(distance) from t_route)");
}
std::string table_route::req_select_min_distance() {
    return std::string("SELECT route_id, shipping_address, arrival_address, distance FROM t_route WHERE distance = (SELECT MIN(distance) from t_route)");
}


std::string table_route::req_select_numbers_of_route_passin_station() {
    std::string name_station;
    std::cout << "enter name station >";
    __ignore_spaces();
    std::getline(std::cin, name_station);

    std::string req = "WITH t1 AS(SELECT t_stop.title_id, t_route.route_id FROM t_stop INNER JOIN t_route "
    		    "ON t_stop.title_id = t_route.shipping_address "
    		    "OR t_stop.title_id = t_route.arrival_address) " 
                "SELECT * FROM t1 WHERE title_id = '" + name_station + "' ORDER BY route_id";
    return req; 
}


std::string table_route::req_select_auto_passing_station() {
    std::string name_station;
    std::cout << "enter name station >";
    __ignore_spaces();
    std::getline(std::cin, name_station);
    
    std::string req = "WITH t1 AS(SELECT t_stop.title_id, t_route.route_id FROM t_stop INNER JOIN t_route " 
            "ON t_stop.title_id = t_route.shipping_address "
            "OR t_stop.title_id = t_route.arrival_address), "
            "t2 AS(SELECT t1.title_id, t_auto.reg_id, t_auto.brand, t_auto.type_auto  FROM t1 INNER JOIN t_auto ON "
            "t1.route_id = t_auto.route_number) "
            "SELECT reg_id, brand, type_auto FROM t2 WHERE title_id = '" + name_station +  "' ORDER BY reg_id";
    return req;
}



#endif