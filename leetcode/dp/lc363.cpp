#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxSumSubmatrix(vector<vector<int>>& grid, int kValue) {
            int n = grid.size();
            int m = grid[0].size();
    
            int res = INT_MIN;
            for(int j = 0; j < m; j++){
                vector<int> temp(n, 0);
                for(int k = j; k < m; k++){
                    for(int i = 0; i < n; i++){
                        temp[i] += grid[i][k];
                    }
    
                    int curr = maxSumSubArrayLessThanK(temp, kValue);
                    res = max(res, curr);
                }
            }
    
            return res;
        }
    
        int maxSumSubArrayLessThanK(vector<int> &v, int k){
            
            // pruning some vectors whose maximum sub array sum <= k
            // significantly increases performance
            int kadaneRes = kadane(v);
            if(kadaneRes <= k) return kadaneRes;
    
            set<int> s;
            s.insert(0);
    
            int sum = 0;
            int res = INT_MIN;
            for(int num : v){
                // prefix sum
                sum += num;
                // sum - prevSum <= k => valid sub array
                // using lower bound we get the max value of the valid subarray
                auto it = s.lower_bound(sum - k);
                if(it != s.end())
                    res = max(res, sum - *it);
                // inserting current sum
                s.insert(sum);
            }
    
            return res;
        }
    
        int kadane(vector<int> &v){
            int sum = 0;
            int res = INT_MIN;
    
            for(int num : v){
                sum += num;
                if(sum > res) res = sum;
                if(sum < 0) sum = 0;
            }
    
            return res;
        }
};