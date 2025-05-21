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
            int max = INT_MIN;
            int sum = 0;
            // for printing the subarray
            int start = -1;
            int subStart = -1;
            int subEnd = -1;
            for(int i = 0; i < nums.size(); i++){
                // it is certain that a new subarray is only started when sum is 0
                // here start refers to the start of the current subarray
                if(sum == 0) start = i;
                // add the current element
                sum += nums[i];
                // when sum is greater than max update the subStart with start & subEnd with i
                if(sum > max){
                    max = sum;
                    subStart = start;
                    subEnd = i;
                }
                // if the sum < 0 why add it forward, start a new subarray by marking the sum as 0
                // if we keep this before the max update then we will lose the case with all -ve numbers
                if(sum < 0) sum = 0;
            }
    
            for(int i = subStart; i <= subEnd; i++) cout << nums[i] << " ";
            cout << endl;
    
            return max;
        }
};