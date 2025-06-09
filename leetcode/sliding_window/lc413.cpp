#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& nums) {
            int n = nums.size();
            if(n < 3) return 0;
            int res = 0;
            int winDiff = nums[1] - nums[0];
            int start, end;
            for(start = 0, end = 1; end < n; end++){
                if(nums[end] - nums[end - 1] != winDiff){
                    int winLen = end - start;
                    res += calc(winLen);
                    start = end - 1;
                    winDiff = nums[end] - nums[end - 1];
                }
            }
            if(end == n){
                res += calc(end - start);
            }
    
            return res;
        }
    
        int calc(int len){
            if(len < 3) return 0;
            else{
                len -= 2;
                return len * (len + 1) / 2;
            }
        }
};