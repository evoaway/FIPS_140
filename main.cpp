#include <iostream>
#include <random>
#include "FIPStest.h"

std::string random_string(std::size_t length)
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, 256);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += (char) distribution(generator);
    }

    return random_string;
}

void runAll(std::string str){

    if(FIPStest::Test(str)){
        std::cout << "Passed!" << std::endl;
    } else {
        std::cout << "Fail!" << std::endl;
    }

    if(FIPStest::Monobit(str)){
        std::cout << "Monobit Passed!" << std::endl;
    } else {
        std::cout << "Monobit Fail!" << std::endl;
    }

    if(FIPStest::LongRun(str)){
        std::cout << "LongRun Passed!" << std::endl;
    } else {
        std::cout << "LongRun Fail!" << std::endl;
    }

    if(FIPStest::Poker(str)){
        std::cout << "Poker Passed!" << std::endl;
    } else {
        std::cout << "Poker Fail!" << std::endl;
    }

    if(FIPStest::Runs(str)){
        std::cout << "Runs Passed!" << std::endl;
    } else {
        std::cout << "Runs Fail!" << std::endl;
    }
    std::cout << std::endl;
}

void test(){
    int len = 2500;
    std::string testString1 = random_string(len);
    runAll(testString1);
    std::string testString2(len, '\0'); // '\0' = 00000000
    runAll(testString2);
    std::string testString3(len, '0'); // '0' = 00110000
    runAll(testString3);
}

int main()
{
    test();
    return 0;
}
