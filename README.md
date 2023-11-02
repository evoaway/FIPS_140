# Project information
FIPS-140 randomness testing of keys
# Description
The project contains a library for evaluating the randomness of bit sequences. Sequences of 20,000 bits are tested using the Monobit test, Longrun test, Poker test and Runs test. The library makes it possible to test the key at once with all 4 tests or each separately
### Functions
All functions accept a `string` of 2500 characters as input and return a boolean `true` or `false`
* `FIPStest::Test(std::string key)` - returns the result of testing the key with all 4 tests;
* `FIPStest::Monobit(std::string key)` - returns true if the number of sequence ones is in the range (9654, 10346);
* `FIPStest::LongRun(std::string key)` - returns true if the length of the series of ones or zeroes is no more than 36;
* `FIPStest::Poker(std::string key)` - returns true if the result of the Poker test is in the range (1.03, 57.4);
* `FIPStest::Runs(std::string key)` - returns true if sequences of length 1, 2, 3, 4, 5, 6 are in valid intervals.
### Additional functions
Key generation function ([source](https://inversepalindrome.com/blog/how-to-create-a-random-string-in-cpp#:~:text=Generating%20a%20random%20string%20in,leaves%20more%20to%20be%20desired.)):
* `random_string(std::size_t length)` - returns a string of the specified length with random characters
# Usage
```c++
std::string rand_key = random_string(len);
bool result = FIPStest::Test(rand_key);
```
```c++
std::string rand_key = random_string(len);
bool monobitTest = FIPStest::Monobit(rand_key);
bool pokerTest = FIPStest::Poker(rand_key);
```
