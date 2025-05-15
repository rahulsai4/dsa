#include<bits/stdc++.h>
using namespace std;

// method 1 using dp
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int> dp(nums.size(), 1);
            int maxVal = 1;
    
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i - 1; j >= 0; j--) {
                    if (nums[i] > nums[j]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                        if (dp[j] == maxVal) break;
                    }
                }
                maxVal = max(maxVal, dp[i]);
            }
    
            return maxVal;
        }
};

// method 2 using bs
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int> arr;
            for(int num : nums){
                int c = findCeil(arr, num);
                if(c == -1) arr.push_back(num);
                else arr[c] = num;
            }      
            return arr.size();
        }
    
        int findCeil(vector<int> &arr, int num){
            if(arr.size() == 0) return -1;
    
            int lo = 0;
            int hi = arr.size() - 1;
            int res = -1;
            while(lo <= hi){
                int mid = (lo + hi) / 2;
    
                if(arr[mid] < num){
                    lo = mid + 1;
                }
                else{
                    res = mid;
                    hi = mid - 1;
                }
            }
    
            return res;
        }
};