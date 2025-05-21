#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            vector<int> pref(n + 1, 0);
            for(vector<int> &q : queries){
                pref[q[0]] -= 1;
                pref[q[1] + 1] += 1;
            }
            for(int i = 1; i <= n; i++){
                pref[i] += pref[i - 1];
            }
    
            for(int i = 0; i < n; i++){
                if(nums[i] + pref[i] > 0) return false;
            }
            return true;
        }
};