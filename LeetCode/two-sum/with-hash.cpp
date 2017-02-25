#include <vector>
#include <unordered_map>


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hash;

        for(int i=0; i<nums.size(); i++){
            int tofind = target - nums[i];

            if(hash.find(tofind)!=hash.end()){
                result.push_back(hash[tofind]);
                result.push_back(i);
                return result;
            }

            hash[nums[i]] = i;
        }
    }
};
