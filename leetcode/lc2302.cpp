#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int winlen = 0;
        long long winsum = 0;
        long long res = 0;

        for(int start = 0, end = 0; end < n; end++){
            winsum += nums[end];
            winlen++;

            while((winsum * winlen) >= k){
                winsum -= nums[start];
                winlen--;
                start++;
            }

            res += winlen;
        }
        return res;
    }
};