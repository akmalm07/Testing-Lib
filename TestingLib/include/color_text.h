#pragma once


#include <iostream>
#include <string>

#define STRINGIFY(x) #x


namespace tester
{

	std::string yellow_text(std::string_view text);

	std::string red_text(std::string_view text);

	std::string green_text(std::string_view text);

    template<typename T>
    inline std::ostream& print_value(std::ostream& os, const T& val)
    {
        if constexpr (std::is_same_v<T, std::string> || std::is_same_v<T, std::string_view> || std::is_same_v<T, const char*>)
            return os << '"' << val << '"';
        else
            return os << val;
    }
}