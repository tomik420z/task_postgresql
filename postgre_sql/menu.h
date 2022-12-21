#pragma once
#ifndef MENU_H
#define MENU_H
#include "p_transport.h"
#include "req_sql.h"
#include <iostream>
#include <string>
#include <vector>
#include "table_traits.h"


class menu {
protected:
        void __print_table_menu() {
                
                std::cout << "1. table station" << std::endl;
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
        

        std::vector<std::string> create_vector_menu(const char* const* vec_strs, size_t sz) {
                std::vector<std::string> res;
                res.reserve(sz + 6);
                res.emplace_back("1. show");
                res.emplace_back("2. select values");
                res.emplace_back("3. update values");
                res.emplace_back("4. insert values");
                res.emplace_back("5. delete values");
                size_t i = 6;
                for(size_t j = 0; j < sz; ++j) {
                        res.emplace_back(std::to_string(i) + ". " + vec_strs[j]);
                        ++i;
                }
                res.emplace_back(std::to_string(i) + ". back");
                return res;
        }      

       

        template<size_t N, size_t I, typename Closure> 
        static constexpr std::enable_if_t<(I == N)> __meta_while(Closure* closure, const Closure* closure1) {}

        template<size_t N, size_t I, class Closure>
        static constexpr std::enable_if_t<(I < N)> __meta_while(Closure* closure, const Closure* closure1){
                closure[I] = closure1[I - 5];
                __meta_while<N, I + 1>(closure, closure1);
        }

        template<size_t N, typename Closure, typename Table>
        static constexpr void meta_while(Closure* closure, const Closure* closure1) {
                closure[0] = std::pair{Table::req_show, 0};
                closure[1] = std::pair{Table::req_select, 0};
                closure[2] = std::pair{Table::req_update, 1};
                closure[3] = std::pair{Table::req_insert, 1};
                closure[4] = std::pair{Table::req_delete_id, 1};
                __meta_while<N, 5>(closure, closure1);
        }
        
        template<size_t __size_add_func, typename Closure, typename Table> 
        static constexpr void initialize_function(const Closure * closure, const Closure* closure1) {
                meta_while<__size_add_func, Closure, Table>(const_cast<Closure*>(closure), closure1); 
        }

        
        template <typename Table> 
        int __menu_table() {
                constexpr auto& v_func = table_traits<Table>::array_function;
                constexpr auto& vec_strs = table_traits<Table>::array_names; 
                constexpr auto sz_vec_strs = table_traits<Table>::size_array_function;
                constexpr auto sz_func = table_traits<Table>::size_array_names;
                constexpr auto size_function = sz_func + 5;
                using type_func = typename table_traits<Table>::function_type; 

                constexpr type_func vec_menu_table[size_function];
                initialize_function<size_function, type_func, Table>(vec_menu_table, v_func);
                
                using std::pair;
                const auto & vec_names = create_vector_menu(Table::vec_strs_names, sz_vec_strs);

                std::string msg;
                int flag_run = 1;
                while(flag_run) {
                        print_menu_table(vec_names);
                        std::cin >> msg;
                        if (!__check_number(msg)) continue;
                
                        std::string::size_type sz;
                        int indx = std::stoi(msg, &sz, 10);
                        
                        if (0 < indx && indx - 1 < size_function) {
                                const auto& [pointer_func, type_req] = vec_menu_table[indx - 1];
                                std::string str_req = (*pointer_func)();

                                std::cout << "------------------------" << std::endl;
                                std::cout << vec_names[indx - 1] << std::endl;
                                if (type_req == 0) {
                                        show_req(std::move(str_req)); 
                                } else if (type_req == 1) {
                                        std::string confirm;
                                        std::cout << "Press key 'e' to continue:";
                                        __ignore_spaces();
                                        if (std::cin.get() == 'e') {
                                                change_data_table(std::move(str_req));
                                        } 
                                        
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
                change_data_table(std::string("SET client_encoding='win1251'"));
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