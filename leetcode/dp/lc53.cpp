#include <bits/stdc++.h>
using namespace std;

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int res = nums[0];
            int s = nums[0];
            for(int i = 1; i < nums.size(); i++){
                s = nums[i] + (s > 0 ? s : 0);
                res = max(res, s);
            }
            return res;
        }
};