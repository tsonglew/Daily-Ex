// Always check the current continous sentence and remeber the maxlen
// keep the index where the chars appear in map

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(256, -1);
        int maxlen, head_minus;
        maxlen = 0;
        head_minus = -1;
        for(int i=0; i<s.length(); i++){
            if(chars[s[i]]>head_minus) head_minus = chars[s[i]];
            chars[s[i]] = i;
            maxlen = max(maxlen, i-head_minus);
        }
        return maxlen;
    }
};
