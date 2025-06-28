#pragma once

#include <iostream>
#include <string>

#include <vector>
#include <functional>

#include "color_text.h" 


namespace tester
{

    struct TestCase
    {
        std::string name;
        std::function<bool()> func;
    };

    class TestRunner
    {
    public:
        void add_test(const std::string& name, std::function<bool()> testFunc);

        void add_tests(const std::vector<TestCase>& tests);

        void run_all();

    private:
        std::vector<TestCase> tests;
    };

}