#pragma once 
#ifndef DB_PUBLIC_STATION_H 
#define DB_PUBLIC_STATION_H 
#include <string>
#include <iostream>

std::string convert_bool(bool v) {
    return v ? std::string("true") : std::string("false");
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

class table_station {
    // columns: title_id, address_id, type_stations
protected:
    static std::string __input_title_id();
    static int __input_rating();
    static bool __input_type();

public:
    table_station() = default;
    ~table_station() = default;

    static const char * req_show();
    static const char* req_select();
    static const char* req_update();
    static const char* req_insert();
    static const char* req_delete_id();
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
 

const char * table_station::req_show() {
    return "SELECT title_id, rating, type_station FROM t_stop ORDER BY title_id";
}

const char* table_station::req_select() {
    std::string id = __input_title_id();
    std::string req = "SELECT title_id, rating, type_station FROM t_stop WHERE title_id = '" + 
                        id + "'";
    std::cout << req << std::endl;
    return req.c_str();
}

const char* table_station::req_update() {
    std::string title_id = __input_title_id();
    int rating = __input_rating();
    bool type_st = __input_type();
    std::string req = "UPDATE t_stop SET rating = " + std::to_string(rating) + 
                    " , type_station = " +  convert_bool(type_st) +  
                    " WHERE title_id = '" + title_id + "'";
    std::cout << req << std::endl;
    return req.c_str();
}

const char* table_station::req_insert() {
    std::string title_id = __input_title_id();
    int rating = __input_rating();
    bool type_st = __input_type();

    std::string req = "INSERT INTO t_stop(title_id, rating, type_station) VALUES('" +   
                title_id + "', " + std::to_string(rating) + ", " + 
                    convert_bool(type_st) + ");";

    std::cout << req << std::endl;
    return req.c_str();
}

const char* table_station::req_delete_id() {
    std::string title_id = __input_title_id();
    std::string req = "DELETE FROM t_stop WHERE title_id = '" + 
                            title_id + "';";
    std::cout << req << std::endl;
    return req.c_str();
}


class table_route {
    // route_id : auto, shipping_address, arrival_address, distance
protected: 
    static int __input_id();
    static std::string __input_sihpping_address();
    static std::string __input_arrival_address();
    static int __input_distance();

public:
    table_route() = default;
    ~table_route() = default;

    static const char * req_show();
    static const char* req_select();
    static const char* req_update();
    static const char* req_insert();
    static const char* req_delete_id();
};

int table_route::__input_id() {
    int id;
    std::cout << "enter 'id'";
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

const char * table_route::req_show() {
    return "SELECT route_id, shipping_address, arrival_address FROM t_route ORDER BY route_id";
}
const char* table_route::req_select() {
    int id = __input_id();
    std::string req =  "SELECT route_id, shipping_address, arrival_address, distance FROM t_route WHERE route_id = "
        + std::to_string(id); 
    std::cout << req << std::endl;
    return req.c_str();
}
const char* table_route::req_update() {
    int id = __input_id();
    std::string shipping_adress = __input_sihpping_address();
    std::string arrival_adress = __input_arrival_address();
    int distance = __input_distance();
    std::string req = "UPDATE shipping_address = '" + shipping_adress + 
    "', arrival_address = '" + arrival_adress +
    + "', distance = " + std::to_string(distance) +  
          " FROM t_route WHERE route_id = " 
        + std::to_string(id);
    std::cout << req << std::endl;
    return req.c_str();
}
const char* table_route::req_insert() {
    std::string shipping_adress = __input_sihpping_address();
    std::string arrival_adress = __input_arrival_address();
    int distance = __input_distance();
    std::string req = "INSERT INTO t_route (shipping_address, arrival_address, distance) VALUES('" 
        + shipping_adress 
        + "', '"  + arrival_adress 
        + "', " + std::to_string(distance) + ")"; 

    std::cout << req << std::endl;
    return req.c_str();
}
const char* table_route::req_delete_id() {
    int id = __input_id();
    std::string req = "DELETE FROM t_route WHERE route_id = " 
        + std::to_string(id);
    std::cout << req.c_str() << std::endl;
    return req.c_str();  
}






class table_vehicle {

protected:
    
public:
    table_vehicle() = default;
    ~table_vehicle() = default;
};

/*
class table_owner {
public:
    using id_t = int;
    using full_name_t = std::string;
    using date_of_birth_t = std::string;
protected:
    id_t address_id;
    full_name_t full_name;
    date_of_birth_t date_of_birth;
public:
    table_owner() = default;
    ~table_owner() = default;

    const char * get_name_class() const noexcept {
        return "t_owner";
    };
};*/


#endif
