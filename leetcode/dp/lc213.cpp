#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int rob(vector<int> &nums){
            int n = nums.size();
            if(n == 1) return nums[0];
    
            int first = nums[0];
            int last = nums[n - 1];
            // first house inc
            nums.pop_back();
            int inc = rob1(nums);
            // first house exc
            nums.erase(nums.begin());
            nums.push_back(last);
            int exc = rob1(nums);
    
            return max(inc, exc);
        }
        int rob1(vector<int>& nums) {
            // rob or skip
            int n = nums.size();
            if(n == 1) return nums[0];
            vector<int> dp(n, 0);
            dp[0] = nums[0];
            dp[1] = max(nums[1], nums[0]);
            for(int i = 2; i < n; i++){
                // rob
                int robHouse = nums[i] + dp[i - 2];
                // skip
                int skipHouse = dp[i - 1];
    
                dp[i] = max(robHouse, skipHouse);
            }
            return dp[n - 1];
        }
};