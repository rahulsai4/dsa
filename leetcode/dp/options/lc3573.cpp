#include <bits/stdc++.h>
using namespace std;

// using 3d dp space n * k * 3
class Solution1 {
    public:
        long long dp[1001][501][3];
        long long mn = -1e14;
        long long maximumProfit(vector<int>& prices, int k) {
            int n = prices.size();
            return helper(prices, 0, k, 0);
        }
    
        // state 
        // 0 => free, 1 => holding, 2 => sold short
        long long helper(vector<int> &prices, int i, int k, int state){
            if(i == prices.size() || k == 0){
                return state == 0 ? 0 : mn;
            }
            if(dp[i][k][state] != 0) return dp[i][k][state];
    
            // skip
            long long res = helper(prices, i + 1, k, state);
    
            if(state == 0){
                // buy or sell short
                res = max(res, -prices[i] + helper(prices, i + 1, k, 1));
                res = max(res, prices[i] + helper(prices, i + 1, k, 2));
            }
            if(state == 1){
                // sell
                res = max(res, prices[i] + helper(prices, i + 1, k - 1, 0));
            }
            else if(state == 2){
                // buy back
                res = max(res, -prices[i] + helper(prices, i + 1, k - 1, 0));
            }
            return dp[i][k][state] = res;
        }
    };