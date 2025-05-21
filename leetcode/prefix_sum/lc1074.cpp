#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numSubmatrixSumTarget(vector<vector<int>>& grid, int target) {
            int n = grid.size();
            int m = grid[0].size();
    
            int res = 0;
            for(int j = 0; j < m; j++){
                vector<int> v(n, 0);
                for(int k = j; k < m; k++){
                    for(int i = 0; i < n; i++){
                        v[i] += grid[i][k];
                    }
    
                    res += subArrayCountOfSumK(v, target);
                }
            }
    
            return res;
        }
    
        int subArrayCountOfSumK(vector<int> &v, int k){
            map<int, int> m;
            m[0]++;
    
            int sum = 0;
            int count = 0;
            for(int num : v){
                sum += num;
                if(m.count(sum - k)){
                    count += m[sum - k];
                }
                m[sum]++;
            }
    
            return count;
        }
    };