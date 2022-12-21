#pragma once
#ifndef TABLE_TRAITS_H
#define TABLE_TRAITS_H

template<typename Table>
class table_traits {
public:
    using function_type = std::pair<std::string (*)(), int>;
    using menu_type = const char* const;


    static constexpr const function_type* array_function = Table::vec_func;
    static constexpr const menu_type* array_names = Table::vec_strs_names;

    static constexpr size_t size_array_names = sizeof(Table::vec_strs_names) / sizeof(menu_type);
    static constexpr size_t size_array_function = sizeof(Table::vec_func) / sizeof(function_type);

    static_assert(size_array_function == size_array_names, "number of requests and number of request names do not match");
    
};


#endif