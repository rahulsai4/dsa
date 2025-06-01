#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long distributeCandies(int n, int limit) {
            long long res = 0;
    
            // a => [0, min(n, limit)]
            for(int a = 0; a <= min(n, limit); a++){
                int left = n - a;
    
                if(left <= 2 * limit){
                    // can divide between b and c => pick 1 and no need to calculate other
                    // b => [bmin, bmax]
                    int bmin = max(0, left - limit);
                    int bmax = min(limit, left);
                    
                    res += (bmax - bmin + 1); 
                }
            }
    
            return res;
        }
        // DP => TLE
        long long helper(int n, int limit, int c, vector<vector<long long>> &dp){
            if(n < 0) return 0;
            if(n == 0) return 1;
            if(c == 0) return 0;
            if(c == 1 && n > limit) return 0;
            if(ceil(n / c) > limit) return 0;
    
            if(dp[n][c] != -1) return dp[n][c];
    
            long long res = 0;
            for(int i = 0; i <= limit; i++){
                res += helper(n - i, limit, c - 1, dp);
            }
    
            return dp[n][c] = res;
        }
};