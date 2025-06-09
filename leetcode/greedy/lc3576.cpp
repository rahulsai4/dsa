#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canMakeEqual(vector<int>& nums, int k) {
            return helper(nums, k, 1) || helper(nums, k, -1);
        }
    
        bool helper(vector<int> nums, int k, int target){
            int n = nums.size();
            int count = 0;
            for(int i = 0; i < n; i++){
                if(i < n - 1){
                    if(nums[i] != target){
                        nums[i] *= -1;
                        nums[i + 1] *= -1;
                        count++;
                    }
                }
            }
            if(nums[n - 1] != target) return false;
            if(count > k) return false;
            return true;
        }
};