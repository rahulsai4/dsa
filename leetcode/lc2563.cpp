#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long res = 0;

        for(int i = 1; i < n; i++){
            int c = ceil(nums, i, lower);
            int f = floor(nums, i, upper);

            if(c == -1 || f == -1 || f < c) continue;
            res += (f - c + 1);
        }

        return res;
    }

    int floor(vector<int> &nums, int hi, int upper){
        int curr = nums[hi];
        hi--;
        int lo = 0;
        int res = -1;

        int oth = upper - curr;
        // other elem <= oth
        while(lo <= hi){
            long long mid = (1ll * lo + hi) / 2;

            if(nums[mid] <= oth){
                lo = mid + 1;
                res = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        return res;
    }
    int ceil(vector<int> &nums, int hi, int lower){
        int curr = nums[hi];
        hi--;
        int lo = 0;
        int res = -1;

        int oth = lower - curr;
        // other elem >= oth
        while(lo <= hi){
            long long mid = (1ll * lo + hi) / 2;

            if(nums[mid] >= oth){
                hi = mid - 1;
                res = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        return res;
    }
};