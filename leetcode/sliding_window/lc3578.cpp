#include <bits/stdc++.h>
using namespace std;

// dp (N*N) => tle
class Solution {
    public:
        int mod = (int) 1e9 + 7;
        int countPartitions(vector<int>& nums, int k) {
            int n = nums.size();
            vector<long long> dp(n + 1, 0);
            dp[n] = 1;
            for(int start = n - 1; start >= 0; start--){
                int mini = nums[start];
                int maxi = nums[start];
    
                long long res = 0;
                for(int end = start; end < n; end++){
                    maxi = max(maxi, nums[end]);
                    mini = min(mini, nums[end]);
                    if(maxi - mini > k) break;
                    res = (res + dp[end + 1]) % mod;
                }
                dp[start] = res;
            }
            return dp[0];
        }
};