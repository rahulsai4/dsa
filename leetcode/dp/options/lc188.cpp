#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            vector<vector<int>> dp(prices.size() + 1, vector<int>(2 * k + 1, -1));
            return helper(prices, 0, 2 * k, dp);
        }
    
        int helper(vector<int> &prices, int i, int trLeft, vector<vector<int>> &dp){
            if(i == prices.size()) return 0;
            if(trLeft == 0) return 0;
    
            if(dp[i][trLeft] != -1) return dp[i][trLeft];
    
            int res = helper(prices, i + 1, trLeft, dp);
            if(trLeft % 2 == 0){
                int buy = -prices[i] + helper(prices, i + 1, trLeft - 1, dp);
                res = max(res, buy);
            }
            else{
                int sell = prices[i] + helper(prices, i + 1, trLeft - 1, dp);
                res = max(res, sell);
            }
    
            return dp[i][trLeft] = res;
        }
};