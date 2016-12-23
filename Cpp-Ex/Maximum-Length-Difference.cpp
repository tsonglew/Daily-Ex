// Description:
//
// You are given two arrays a1 and a2 of strings. Each string is composed with letters from a to z. Let x be any string in the first array and y be any string in the second array.
//
// Find max(abs(length(x) − length(y)))
//
// If a1 or a2 are empty return -1 in each language except in Haskell where you will return Nothing.
//
// Example:
//
// s1 = ["hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"]
// s2 = ["cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"]
// mxdiflg(s1, s2) --> 13
#include <vector>
#include <cmath>
#include <string>

class MaxDiffLength
{
public:
    static int mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2);
};

int MaxDiffLength::mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2) {
    double mx = -1;
    double min = -1;
    for(auto x1: a1) {
        for(auto x2: a2) {
            double x1_l = x1.length(), x2_l = x2.length();
            min = std::abs(x1_l-x2_l);
            if(min>mx)
                mx = min;
        }
    }
    return static_cast<int>(mx);
}
