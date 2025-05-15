#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int rob(vector<int>& nums) {
            return rob1(nums);
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