#include "FIPStest.h"

bool FIPStest::Test(std::string key) {
    CheckLength(key.length());
    bool monobit = Monobit(key);
    bool longrun = LongRun(key);
    bool poker = Poker(key);
    bool runs = Runs(key);
    return monobit && longrun && poker && runs;
}

bool FIPStest::Monobit(std::string key) {
    CheckLength(key.length());
    int one_count = 0;
    for (int i = 0; i < key.length(); ++i) {
        std::bitset<8> byte(key[i]);
        for (int j = 0; j < 8; ++j) {
            if(byte[j]) {
                one_count++;
            }
        }
    }
    return (one_count > MONOBIT_MIN) && (one_count < MONOBIT_MAX);
}

bool FIPStest::LongRun(std::string key) {
    CheckLength(key.length());
    int zeroSeries = 0;
    int oneSeries = 0;
    for (int i = 0; i < key.length(); ++i) {
        std::bitset<8> byte(key[i]);
        for (int j = 0; j < 8; ++j) {
            if(byte[j]){
                zeroSeries = 0;
                oneSeries++;
            } else {
                oneSeries = 0;
                zeroSeries++;
            }
            if(zeroSeries > LONG_RUN_MAX || oneSeries > LONG_RUN_MAX) {
                return false;
            }
        }
    }
    return true;
}

bool FIPStest::Poker(std::string key) {
    CheckLength(key.length());
    size_t n[16] = {0};
    int m = 4;
    for (int i = 0; i < key.length(); ++i) {
        char block1 = (key[i] >> 4) & 0xF;
        char block2 = key[i] & 0x0F;
        for (int j = 0; j < 16; ++j) {
            if(j == block1)
                n[j]++;
            if(j == block2)
                n[j]++;
        }
    }
    size_t sum = 0;
    for (int i = 0; i < 16; ++i) {
        sum += n[i] * n[i];
    }
    int k = key.length() * 8 / m;
    double x = pow(2, double(m)) / k * sum - k;
    return (x > POKER_MIN) && (x < POKER_MAX);
}

bool FIPStest::Runs(std::string key) {
    CheckLength(key.length());
    int zeroSeries[6] = {0};
    int oneSeries[6] = {0};
    int oneCount = 0;
    int zeroCount = 0;
    for (int i = 0; i < key.length(); ++i) {
        std::bitset<8> byte(key[i]);
        for (int j = 0; j < 8; ++j) {
            if(byte[j]) {
                oneCount++;
                if(zeroCount > 0){
                    if(zeroCount >= 6){
                        ++zeroSeries[5];
                    }
                    else {
                        ++zeroSeries[zeroCount - 1];
                    }
                    zeroCount = 0;
                }
            } else  {
                zeroCount++;
                if(oneCount > 0){
                    if(oneCount >= 6){
                        ++oneSeries[5];
                    }
                    else {
                        ++oneSeries[oneCount - 1];
                    }
                    oneCount = 0;
                }
            }
        }
    }
    for (int i = 0; i < 6; ++i) {
        bool zeroInInterval = (zeroSeries[i] > SERIES_LENGTH[i][0]) && (zeroSeries[i] < SERIES_LENGTH[i][1]);
        bool oneInInterval = (oneSeries[i] > SERIES_LENGTH[i][0]) && (oneSeries[i] < SERIES_LENGTH[i][1]);
        if(!zeroInInterval || !oneInInterval) {

            return false;
        }
    }
    return true;
}

void FIPStest::CheckLength(int len) {
    if (len != 2500) {
        throw std::length_error("The length of the key must be 2500 characters!");
    }
}




