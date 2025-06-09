#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int combinationSum4(vector<int>& nums, int target) {
            vector<unsigned int> dp(target + 1, 0);
            dp[0] = 1;
            for(int i = 1; i <= target; i++){
                for(int coin : nums){
                    if(i - coin >= 0){
                        dp[i] += dp[i - coin];
                    }
                }
            }
            return dp[target];
        }
};