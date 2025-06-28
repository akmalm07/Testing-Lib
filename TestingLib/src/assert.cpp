#include "include/assert.h"

namespace tester
{
    void assert_fail(const std::string& message, std::source_location loc)

    {
        std::cerr << red_text("Assertion failed: ") << message
            << " at " << loc.file_name() << ":" << loc.line() << "\n";
        std::abort();
    }


    void assert_true(bool condition, const std::string& msg, std::source_location loc)

    {
        if (!condition)
        {
            assert_fail(msg.empty() ? "Condition is false" : msg, loc);
        }
    }
    void assert_false(bool condition, const std::string& msg, std::source_location loc)

    {
        if (condition)
        {
            assert_fail(msg.empty() ? "Condition is true" : msg, loc);
        }
    }
}

