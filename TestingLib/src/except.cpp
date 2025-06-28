#include "include/except.h"


namespace tester
{

    void expect_fail(const std::string& message, std::source_location loc)
    {
        std::cerr << yellow_text("Expectation failed: ") << message
            << " at " << loc.file_name() << ":" << loc.line() << "\n";
    }

    void expect_true(bool condition, const std::string& msg, std::source_location loc)
    {
        if (!condition)
        {
            expect_fail(msg.empty() ? "Condition is false" : msg, loc);
        }
        else
        {
            std::cout << green_text("Expectation passed") << ": " << (msg.empty() ? "(no message)" : msg) << "\n";
        }
    }

    void expect_false(bool condition, const std::string& msg, std::source_location loc)
    {
        if (condition)
        {
            expect_fail(msg.empty() ? "Condition is true" : msg, loc);
        }
        else
        {
            std::cout << green_text("Expectation passed") << ": " << (msg.empty() ? "(no message)" : msg) << "\n";
        }
    }

}