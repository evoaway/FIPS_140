
#ifndef FIPS_140_FIPSTEST_H
#define FIPS_140_FIPSTEST_H


#include <string>
#include <bitset>
#include <iostream>
#include <cmath>

class FIPStest {
public:
    static bool Test(std::string key);
    static bool Monobit(std::string key);
    static bool LongRun(std::string key);
    static bool Poker(std::string key);
    static bool Runs(std::string key);
    static const int MONOBIT_MIN = 9654;
    static const int MONOBIT_MAX = 10346;
    static const int LONG_RUN_MAX = 36;
    constexpr static const double POKER_MIN = 1.03;
    constexpr static const double POKER_MAX = 57.4;
    constexpr static const int SERIES_LENGTH[6][2] = {{2267, 2733}, {1079, 1421},
                                                      {502, 748}, {223, 402},
                                                      {90, 223}, {90, 223}};
private:
    static void CheckLength(int len);
};


#endif //FIPS_140_FIPSTEST_H
