#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        bitset<2001> unique = 0;
        int count = 0;
        for(int num : nums){
            if(unique[num]) continue;
            count++;
            unique[num] = 1;
        }
        int target = count;

        // sliding window
        int res = 0;
        int freq[2001] = {0};
        int n = nums.size();
        count = 0;
        for(int start = 0, end = 0; end < n; end++){
            if(freq[nums[end]] == 0) count++;
            freq[nums[end]]++;

            while(count == target){
                res += (n - end);
                freq[nums[start]]--;
                if(freq[nums[start]] == 0){
                    count--;;
                }
                start++;
            }
        }

        return res;
    }
};