#include<bits/stdc++.h>
using namespace std;

// dp memo
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            // consider state approach
            // 0 - buy
            // 1 - sell
            int n = prices.size();
            vector<vector<int>> dp(n, vector<int>(2, -1));
            return helper(prices, 0, false, dp);
        }
    
        int helper(vector<int> &prices, int i, int bought, vector<vector<int>> &dp){
            if(i >= prices.size()) return 0;
    
            if(dp[i][bought] != -1) return dp[i][bought];
    
            if(bought == 1){
                int sell = prices[i] + helper(prices, i + 2, 0, dp);
                int cooldown = helper(prices, i + 1, 1, dp);
                return dp[i][1] = max(cooldown, sell);
            }
            else{
                int buy = helper(prices, i + 1, 1, dp) - prices[i];
                int cooldown = helper(prices, i + 1, 0, dp);
                return dp[i][0] = max(cooldown, buy);
            }
        }
};

// backtracking
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            return backtrack(prices, 0, false, 0);
        }
    
        int backtrack(vector<int>& prices, int i, bool bought, int profit) {
            if (i >= prices.size()) return profit;
    
            if (bought) {
                int sell = backtrack(prices, i + 2, false, profit + prices[i]);
                int hold = backtrack(prices, i + 1, true, profit);
                return max(sell, hold);
            } else {
                int buy = backtrack(prices, i + 1, true, profit - prices[i]);
                int skip = backtrack(prices, i + 1, false, profit);
                return max(buy, skip);
            }
        }
};
    