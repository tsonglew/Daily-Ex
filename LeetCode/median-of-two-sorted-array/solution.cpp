#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    double search_one(vector<int>& nums1, vector<int>& nums2, int should_bigger, int total_length){
        int start = 0;
        int end = (int)nums1.size() - 1;
        while(start<=end){
            int mid = (start+end)/2;
            int mid_num = nums1[mid];
            int left_in_second = should_bigger-mid-1;
            
            if(mid_num>=nums2[left_in_second]){
                if(left_in_second==nums2.size()-1||mid_num<=nums2[left_in_second+1]){
                    return total_length%2==0?even_check(nums1, nums2, mid_num, mid, left_in_second):mid_num;
                }
                end = mid - 1;
            } else if (left_in_second==nums2.size()-1||mid_num<=nums2[left_in_second+1]){
                start = mid + 1;
            }
        }
        throw 1;
    }
    
    double even_check(vector<int>& nums1, vector<int>& nums2, int mid_num, int mid, int left_in_second){
        int mid_bigger;
        mid_bigger = nums2[left_in_second+1]<mid_num?nums1[mid+1]:(mid+1<=nums1.size()-1&&nums1[mid+1]<nums2[left_in_second+1])?nums1[mid+1]:nums2[left_in_second+1];
        return ((double)mid_num+(double)mid_bigger)/2;
    }
    
    double single_search(vector<int>& nums){
        int length = (int)nums.size();
        return length%2==0?((double)nums[length/2-1]+(double)nums[length/2])/2:(double)nums[length/2];
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int should_bigger;
        int nums1_length = (int)nums1.size();
        int nums2_length = (int)nums2.size();
        int total_length = nums1_length + nums2_length;
        if (nums1_length==0) {
            return single_search(nums2);
        }
        if (nums2_length==0) {
            return single_search(nums1);
        }
        should_bigger = total_length%2==0?total_length/2-1:total_length/2;
        try{
            return search_one(nums1, nums2, should_bigger, total_length);
        } catch(int){
            return search_one(nums2, nums1, should_bigger, total_length);
        }
        return 0;
    }
};
