#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numDistinct(string s, string t) {
            int n = s.length();
            int m = t.length();
            if(n < m) return 0;
    
            vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1));
    
            return helper(s, t, n, m, dp);
        }
    
        int helper(string &s, string &t, int n, int m, vector<vector<long long>> &dp){
            if(m == 0) return 1;
            if(n == 0) return 0;
    
            if(dp[n][m] != -1) return dp[n][m];
    
            long long res = helper(s, t, n - 1, m, dp);
            if(s[n - 1] == t[m - 1]){
                res += helper(s, t, n - 1, m - 1, dp);
            }
    
            return dp[n][m] = res;
        }
};