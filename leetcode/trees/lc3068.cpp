#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
            long long res = 0;
            int count = 0;
            int diff = INT_MAX;
            for(int num : nums){
                int x = num ^ k;
                if(x > num){
                    count++;
                    res += x;
                } else res += num;
                // must sac one num ^ k or num
                // finding the minimum to sac
                diff = min(diff, abs(x - num));
            }
    
            return res - (count % 2 == 0 ? 0 : diff);
        }
};