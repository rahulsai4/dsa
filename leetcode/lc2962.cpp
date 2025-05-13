#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0;
        for(int num : nums) mx = max(num, mx);

        int n = nums.size();
        int count = 0;
        long long res = 0;
        for(int start = 0, end = 0; end < n; end++){
            if(nums[end] == mx){
                count++;
            }

            while(count == k){
                res += (n - end);
                if(nums[start] == mx) count--;
                start++;
            }
        }
        return res;
    }
};