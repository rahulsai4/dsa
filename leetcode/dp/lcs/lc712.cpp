#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++)
            dp[i][0] = dp[i - 1][0] + ((int)s1[i - 1]);
        for(int j = 1; j <= m; j++)
            dp[0][j] = dp[0][j - 1] + ((int)s2[j - 1]);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }

        return dp[n][m];
    }

    int helper(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if(i == 0 || j == 0) {
            int res = 0;
            while(i != 0) {
                res += ((int)s1[i - 1]);
                i--;
            }
            while(j != 0) {
                res += ((int)s2[j - 1]);
                j--;
            }
            return res;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX;
        if(s1[i - 1] == s2[j - 1]) {
            res = min(res, helper(s1, s2, i - 1, j - 1, dp));
        } else {
            int del1 = (int)s1[i - 1] + helper(s1, s2, i - 1, j, dp);
            int del2 = (int)s2[j - 1] + helper(s1, s2, i, j - 1, dp);
            res = min(res, del1);
            res = min(res, del2);
        }

        return dp[i][j] = res;
    }
};