#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int count = 0;
        int maxProfit(vector<int>& prices) {
            vector<vector<int>> dp(prices.size(), vector<int>(5, -1));
            return helper(prices, 4, 0, dp);
        }
    
        int helper(vector<int> &prices, int trLeft, int i, vector<vector<int>> &dp){
            if(i == prices.size() || trLeft == 0){
                return 0;
            }
    
            if(dp[i][trLeft] != -1) return dp[i][trLeft];
    
            // skip i
            int res = helper(prices, trLeft, i + 1, dp);
    
            // trLeft - even => buy
            if(trLeft % 2 == 0){
                int buy = helper(prices, trLeft - 1, i + 1, dp) - prices[i];
                res = max(res, buy);
            }
            // trLeft - odd => sell
            else{
                int sell = max(0, helper(prices, trLeft - 1, i + 1, dp)) + prices[i];
                res = max(res, sell);
            }
    
            return dp[i][trLeft] = res;
        }
};