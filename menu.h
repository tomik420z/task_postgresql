#pragma once
#ifndef MENU_H
#define MENU_H
#include "p_transport.h"
#include "req_sql.h"
#include <iostream>
#include <string>
#include <vector>
#include <functional>

class menu {
protected:
        void __print_table_menu() {
                std::cout << "1. table stop" << std::endl;
                std::cout << "2. table route" << std::endl;
                std::cout << "3. table auto" << std::endl;
                std::cout << "4. table owner" << std::endl;
                std::cout << "5. make a select request" << std::endl;
                std::cout << "6. make a change request" << std::endl;
                std::cout << "7. quit" << std::endl;
                std::cout << "choose menu item > " << std::endl;
        }


        int __make_select_req() {
                std::string req;
                while(std::cin.peek() == ' ') {
                        std::cin.get();
                }
                if (std::cin.peek() == '\n') {
                        std::cin.ignore();
                }
                std::getline(std::cin, req);
                
                show_req(std::move(req));
                return 1;
        }

        int __make_change_req() {
                std::string req;
                while(std::cin.peek() == ' ') {
                        std::cin.get();
                }
                if (std::cin.peek() == '\n') {
                        std::cin.ignore();
                }
                std::getline(std::cin, req);
                change_data_table(std::move(req));
                return 1;
        }

        bool __check_number(const std::string & str) {
                auto is_digit = [](char ch) {                                
                        return ('0' <= ch && ch <= '9') ? true : false;
                };

                for(auto ch : str) {
                        if (!is_digit(ch)) {
                                return false;
                        }
                }
                return true;
        }

        
        void print_menu_table(const std::vector<std::string> & vec_strs) {
                for(const auto & str : vec_strs) {
                        std::cout << str << std::endl;
                }
                std::cout << "choose menu item > " << std::endl;
        } 
        

        std::vector<std::string> create_vector_menu(const std::vector<std::string> & vec_strs) {
                std::vector<std::string> res;
                res.reserve(vec_strs.size() + 6);
                res.emplace_back("1. show");
                res.emplace_back("2. select values");
                res.emplace_back("3. update values");
                res.emplace_back("4. insert values");
                res.emplace_back("5. delete values");
                size_t i = 6;
                for(const auto & str : vec_strs) {
                        res.emplace_back(std::to_string(i) + ". " + str);
                        ++i;
                }
                res.emplace_back(std::to_string(i) + ". back");
                return res;
        }      


        template <typename Table> 
        int __menu_table() { 
                using std::pair;
                typename Table::arr_additional_func vec_menu_table({pair{Table::req_show, 0}, 
                                       pair{Table::req_select, 0}, pair{Table::req_update, 1}, 
                                            pair{Table::req_insert, 1}, pair{Table::req_delete_id, 1}});
                             
                const auto& v_func = Table::vec_func;

                for(const auto& __func : v_func) {
                        vec_menu_table.push_back(__func);
                }

                const auto & vec_names = create_vector_menu(Table::vec_strs_names);
                
                std::string msg;
                int flag_run = 1;
                while(flag_run) {
                        print_menu_table(vec_names);
                        std::cin >> msg;
                        if (!__check_number(msg)) continue;

                        std::string::size_type sz;
                        int indx = std::stoi(msg, &sz, 10);
                        
                        if (0 < indx && indx - 1 < vec_menu_table.size()) {
                                const auto& [pointer_func, type_req] = vec_menu_table[indx - 1];
                                std::cout << "------------------------" << std::endl;
                                std::cout << vec_names[indx - 1] << std::endl;
                                if (type_req == 0) {
                                        show_req(std::move((*pointer_func)()));
                                } else if (type_req == 1) {
                                        change_data_table(std::move((*pointer_func)()));
                                }  
                                std::cout << "------------------------" << std::endl;
                        } else if (indx == vec_names.size()) {
                                flag_run = 0;
                        }      
                }
                return 1;
        }

        const std::vector<int (menu::*)()> vec_menu;
        
        int __exit_state() {
                return 0;
        }

        

public:
        menu() : vec_menu({__menu_table<table_station>, __menu_table<table_route>, 
                        __menu_table<table_auto>, __menu_table<table_owner>, __make_select_req, __make_change_req, __exit_state}) {}

        void exec() {
                int flag_run = 1;
                std::string msg;
                while(flag_run) {
                        __print_table_menu();
                        std::cin >> msg;
                        if (!__check_number(msg)) continue;
                        std::string::size_type sz;
                        int indx = std::stoi(msg, &sz, 10);
                        if (0 < indx && indx - 1 < vec_menu.size()) {
                               flag_run = (this->*vec_menu[indx - 1])();   
                        }      
                }
        }

        ~menu() {}

};


#endif