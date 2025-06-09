#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minSteps(int n) {
            vector<int> dp(n + 1, 0);
            for(int i = 2; i <= n; i++){
                dp[i] = i;
                for(int j = i - 1; j > 1; j--){
                    if(i % j == 0){
                        dp[i] = dp[j] + (i / j);
                        break;
                    }
                }
            }
            return dp[n];
        }

        // slow
        int helper(int n, int curr, int copy, vector<vector<int>> &dp){
            if(curr == n) return 0;
            if(curr > n || curr + copy > n) return 1002;
    
            if(dp[curr][copy] != -1) return dp[curr][copy];
    
            int res = INT_MAX;
            // copy
            if(curr != copy){
                res = min(res, 1 + helper(n, curr, curr, dp));
            }
            // paste
            if(copy != 0){
                res = min(res, 1 + helper(n, curr + copy, copy, dp));
            }
    
            return dp[curr][copy] = res;
        }
 };