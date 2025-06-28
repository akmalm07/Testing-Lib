#pragma once

#include <iostream>
#include <string>
#include <source_location>
#include <sstream>

#include "color_text.h"

namespace tester
{

    // Core expect (non-fatal)
    void expect_fail(const std::string& message, std::source_location loc);


    // === EXPECTS (non-fatal) ===

    void expect_true(bool condition, const std::string& msg = {}, std::source_location loc = std::source_location::current());


    void expect_false(bool condition, const std::string& msg = {}, std::source_location loc = std::source_location::current());

    template<typename T>
    inline void expect_eq(const T& a, const T& b, std::string msg = {}, std::source_location loc = std::source_location::current())
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

            expect_fail(oss.str(), loc);
        }
        else
        {
            std::cout << green_text("Expectation passed") << ": "
                << (msg.empty() ? "(no message)" : msg) << "\n";
        }
    }

    template<typename T>
    inline void expect_ne(const T& a, const T& b, std::string msg = {}, std::source_location loc = std::source_location::current())
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

            expect_fail(oss.str(), loc);
        }
        else
        {
            std::cout << green_text("Expectation passed") << ": "
                << (msg.empty() ? "(no message)" : msg) << "\n";
        }
    }

}