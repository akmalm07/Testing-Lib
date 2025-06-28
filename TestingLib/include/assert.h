#pragma once

#include <iostream>
#include <string>
#include <source_location>
#include <sstream>

#include "color_text.h"


namespace tester
{
    // === ASSERTS (fatal) ===

    // Core assert (fatal)
    
    void assert_fail(const std::string& message, std::source_location loc);


    void assert_true(bool condition, const std::string& msg = {}, std::source_location loc = std::source_location::current());


    void assert_false(bool condition, const std::string& msg = {}, std::source_location loc = std::source_location::current());

    template<typename T>
    inline void assert_eq(const T& a, const T& b, std::string msg = {}, std::source_location loc = std::source_location::current())
    {
        if (!(a == b))
        {
            std::ostringstream oss;

            if (!msg.empty())
                oss << msg << " ";
            else
                oss << "Values not equal: ";

            oss << "expected ";
            print_value(oss, a);
            oss << ", got ";
            print_value(oss, b);

            assert_fail(oss.str(), loc);
        }
    }


    template<typename T>
    inline void assert_ne(const T& a, const T& b, std::string msg = {}, std::source_location loc = std::source_location::current())
    {
        if (a == b)
        {
            std::ostringstream oss;

            if (!msg.empty())
                oss << msg << " ";
            else
                oss << "Values equal but expected different: ";

            oss << "both are ";
            print_value(oss, a);

            assert_fail(oss.str(), loc);
        }
    }

}