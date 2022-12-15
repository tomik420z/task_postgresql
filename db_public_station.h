#pragma once 
#ifndef DB_PUBLIC_STATION_H 
#define DB_PUBLIC_STATION_H 
#include <string>
#include <iostream>


class table_station {
    // columns: address_id, title, type_stations
public:
    table_station() = default;
    ~table_station() = default;

    int input_addres() const {
        int id_address;
        std::cout << "enter 'address_id' >"; 
        std::cin >> id_address;
        return id_address;
    }

    std::string input_title() const {
        std::string title;
        std::cout << "enter 'title' >";
        std::cin >> title;
        return title;
    } 

    int input_type_station() const {
        int type_st;
        std::cout << "enter 'type_station' >"; 
        std::cin >> type_st;
        return type_st;
    }
    
    char * req_show() const noexcept {
        return "SELECT address_id, title, type_station FROM t_stop ORDER BY address_id";
    }
    
    const char* req_select() const {
        int id = input_addres();
        std::string req = "SELECT address_id, title, type_station FROM t_stop WHERE address_id = " + 
                            std::to_string(id);
        std::cout << req << std::endl;
        return req.c_str();
    }

    const char* req_update() const {
        int id_address = input_addres();
        std::string title = input_title();
        int type_st = input_type_station();
        std::string req = "UPDATE t_stop SET title = '" + title + 
                        "' , type_station = " +  std::to_string(type_st) +  
                        " WHERE address_id = " + std::to_string(id_address);
        std::cout << req << std::endl;
        return req.c_str();
    }

    const char* req_insert()  const {
        int id_address = input_addres();
        std::string title = input_title();
        int type_st = input_type_station();

        std::string req = "INSERT INTO t_stop(address_id, title, type_station) VALUES(" +
                            std::to_string(id_address) + ", '" + title + 
                            "', " + std::to_string(type_st)  + ")";
        std::cout << req << std::endl;
        return req.c_str();
    }

    const char* req_delete_id() const {
        int id_address = input_addres();
        std::string req = "DELETE FROM t_stop WHERE address_id = " + 
                                std::to_string(id_address);
        std::cout << req << std::endl;
        return req.c_str();
    }
};


class table_route {
public:
    using id_t = int;
    using distance_t = int;
protected: 
    id_t route_id;
    distance_t distance;
public:
    table_route() = default;
    ~table_route() = default;

    const char * get_name_class() const noexcept {
        return "t_route";
    };
};

class table_vehicle {
public:
    using id_t = int;
    using brand_t = std::string;
    using vehicle_t = std::string;
protected:
    id_t registration_number_id;
    brand_t brand;
    vehicle_t vehicle_type;
public:
    table_vehicle() = default;
    ~table_vehicle() = default;

    const char * get_name_class() const noexcept {
        return "t_vechicle";
    };
};


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
};


#endif
