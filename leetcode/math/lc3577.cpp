#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long res = 0;
        int mod = (int) 1e9 + 7;
        int countPermutations(vector<int>& nums) {
            int n = nums.size();
            int minVal = *min_element(++nums.begin(), nums.end());
            if(minVal <= nums[0]) return 0;
    
            long long res = 1;
            for(int i = n - 1; i >= 1; i--){
                res = (res * i) % mod;
            }
    
            return res;
        }
};