#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class MaxSubString {
private:
    int DivideSub(vector<int> nums, int left, int right) {
        int sum = 0;
        if(left==right) {
            return nums[left]>0?nums[left]:0;
        }
        int center = (left+right) / 2;
        int lhalfmax = DivideSub(nums, left, center);
        int rhalfmax = DivideSub(nums, center+1, right);
        
        int lmax = 0, lsum = 0;
        for(int i=center; i>=left; i--) {
            lsum += nums[i];
            if(lsum > lmax) {
                lmax = lsum;
            }
        }
        lsum = lmax;
        for(int i=center+1; i<=right; i++) {
            lsum += nums[i];
            if(lsum > lmax) {
                lmax = lsum;
            }
        }
        sum = lmax;
        sum = sum<lhalfmax?lhalfmax:sum;
        sum = sum<rhalfmax?rhalfmax:sum;
        return sum;
    }
public:
    void Brute(vector<int> nums) {
        cout << "Starting Brute..." << endl;
        auto start = chrono::steady_clock::now();
        
        int size = static_cast<int>(nums.size());
        int max = 0;
        for(int i=0; i<size; i++) {
            int sum = 0;
            for(int j=i; j<size; j++) {
                sum += nums[j];
                if(sum > max) {
                    max = sum;
                }
            }
        }
        cout << "Max Substring Sum: " << max << endl;
        
        auto end = chrono::steady_clock::now();
        cout << "Finished in " << chrono::duration_cast<chrono::nanoseconds>(end-start).count()
        << " nanoseconds." << endl << endl;
    }
    
    void Divide(vector<int> nums) {
        cout << "Starting Divide..." << endl;
        auto start = chrono::steady_clock::now();
        cout << "Max Substring Sum: " << DivideSub(nums, 0, static_cast<int>(nums.size()-1)) << endl;
        auto end = chrono::steady_clock::now();
        cout << "Finished in " << chrono::duration_cast<chrono::nanoseconds>(end-start).count()
        << " nanoseconds." << endl << endl;
    }
    
    void DP(vector<int> nums) {
        cout << "Starting DP..." << endl;
        auto start = chrono::steady_clock::now();
        
        int max = 0, sum = 0;
        int size = static_cast<int>(nums.size());
        for(int i=0; i<size; i++) {
            sum = sum>0?sum+nums[i]:nums[i];
            max = sum>max?sum:max;
        }
        cout << "Max Substring Sum: " << max << endl;
        
        auto end = chrono::steady_clock::now();
        cout << "Finished in " << chrono::duration_cast<chrono::nanoseconds>(end-start).count()
        << " nanoseconds." << endl << endl;
    }
};

int main() {
    int arr[] = {-5, 11, -4, 13,-4, -2, 1, 20, 8, 3, -5, 9, 10, -4, 20, -18, -4};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    cout << "Get Max Substring sum of: [";
    for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++) {
        cout << *it << ",";
    }
    cout << "]" << endl << endl;
    MaxSubString m;
    m.Brute(nums);
    m.Divide(nums);
    m.DP(nums);
    return 0;
}
