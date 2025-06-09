#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool predictTheWinner(vector<int>& nums) {
            int n = nums.size();
            vector<int> pref(n + 1, 0);
            for(int i = 1; i <= n; i++){
                pref[i] = nums[i - 1] + pref[i - 1];
            }
    
            vector<vector<int>> dp(n, vector<int>(n, -1));
    
            int p1 = canWin(nums, 0, n - 1, pref, dp);
            int p2 = pref[n] - p1;
    
            return p1 >= p2;
        }
    
        int canWin(vector<int>& nums, int i, int j, vector<int>& pref, vector<vector<int>> &dp){
            if(i > j) return 0;
            if(i == j) return nums[i];
    
            if(dp[i][j] != -1) return dp[i][j];
    
            int subarraysum = pref[j + 1] - pref[i];
            // first 
            int p1firstp2 = canWin(nums, i + 1, j, pref, dp);
            int p1firstp1 = subarraysum - p1firstp2;
            // last
            int p1lastp2 = canWin(nums, i, j - 1, pref, dp);
            int p1lastp1 = subarraysum - p1lastp2;
    
            return dp[i][j] = max(p1lastp1, p1firstp1);
        }
};