#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars;
        int maxlen, head_minus;
        maxlen = 0;
        head_minus = 0;
        for(int i=0; i<s.length(); i++){
            if(chars[s[i]]>head_minus){
                head_minus = chars[s[i]];
            }
            chars[s[i]] = i+1;
            maxlen = max(maxlen, (i+1)-head_minus);
        }
        return maxlen;
    }
};
