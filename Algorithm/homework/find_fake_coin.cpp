#include <iostream>
#include <vector>

using namespace std;

int SubFake(vector<int> nums, int half_len, int right_plus, int authentic){
    int left_sum = 0, right_sum = 0;
    for(int i=0; i<half_len-1; i++) {
        left_sum += nums[i];
        right_sum += nums[i+right_plus];
    }
    
    if(left_sum==right_sum){
        if(nums[half_len-1]==authentic){
            return half_len+right_plus-1;
        } else {
            return half_len-1;
        }
    } else if(left_sum<right_sum){
        if(left_sum-nums[half_len-1]+nums[half_len+right_plus-1]
           < right_sum+nums[half_len-1]-nums[half_len+right_plus-1]){
            return SubFake(nums, half_len-2, right_plus, authentic);
        } else {
            return (nums[half_len-1]!=authentic)?(half_len-1):(half_len+right_plus-1);
        }
    } else if (left_sum>right_sum){
        if(left_sum-nums[half_len-1]+nums[half_len+right_plus-1]
           > right_sum+nums[half_len-1]-nums[half_len+right_plus-1]){
            return SubFake(nums, half_len-2, right_plus, authentic);
        } else {
            return (nums[half_len-1]!=authentic)?(half_len-1):(half_len+right_plus-1);
        }
    }
    return SubFake(nums, half_len-1, right_plus, authentic);
}

int FakeCoin(vector<int> nums){
    int length = static_cast<int>(nums.size());
    int authentic;
    if(length < 3){
        return -1;
    }
    if(length%2!=0){
        int last = nums[length-1];
        nums.pop_back();
        if(last!=nums[0]&&last!=nums[1]){
            return length-1;
        }
        authentic = last;
        return SubFake(nums, length/2, length/2, authentic);
    } else {
        if(nums[length/2-1]!=nums[length-1]){
            if(nums[length/2-1]==nums[0]){
                return length-1;
            } else {
                return length/2-1;
            }
        }
        authentic = nums[length/2-1];
        return SubFake(nums, length/2-1, length/2, authentic);
    }
}
