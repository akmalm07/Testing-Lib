#include "include/test_case.h"



namespace tester
{
    void TestRunner::add_test(const std::string& name, std::function<bool()> testFunc)
    {
        tests.push_back({ name, testFunc });
    }

    void TestRunner::add_tests(const std::vector<TestCase>& tests)

    {
        this->tests.insert(this->tests.end(), tests.begin(), tests.end());

    }

    void TestRunner::run_all()
    {
        int passed = 0;
        int failed = 0;

        for (auto& test : tests) {
            std::cout << "Running test: " << test.name << "\n";

            bool result = test.func(); 

            if (result) {
                std::cout << green_text("[PASS] ") << test.name << "\n";
                ++passed;
            }
            else {
                std::cout << red_text("[FAIL] ") << test.name << "\n";
                ++failed;
            }
        }

        std::cout << "\nTests finished.\n\n\t" << green_text("Passed: ") << passed << ", " << red_text("Failed: ") << failed << "\n";
    }


}