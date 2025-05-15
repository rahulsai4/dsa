#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int integerBreak(int n) {
            vector<int> dp(n + 1, 0);
            dp[1] = 1;
            dp[2] = 1;
            for(int i = 3; i <= n; i++){
                for(int j = 2; j < i; j++){
                    // divide into parts
                    int left = max(j, dp[j]);
                    int right = max(i - j, dp[i - j]);
                    dp[i] = max(dp[i], left * right);
                }
            }
            return dp[n];
        }
};