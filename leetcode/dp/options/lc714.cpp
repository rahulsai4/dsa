#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            vector<vector<int>> dp(n, vector<int>(2, -1));
            return helper(prices, 0, prices.size(), true, fee, dp);
        }
        
        int helper(vector<int> &prices, int i, int n, int canBuy, int fee, vector<vector<int>> &dp){
            if(i == n) return 0;
            if(dp[i][canBuy] != -1) return dp[i][canBuy];
    
            int res = helper(prices, i + 1, n, canBuy, fee, dp);
            if(canBuy){
                res = max(res, -prices[i] + helper(prices, i + 1, n, false, fee, dp));
            }
            else{
                res = max(res, prices[i] - fee + helper(prices, i + 1, n, true, fee, dp));
            }
            return dp[i][canBuy] = res;
        }
    };