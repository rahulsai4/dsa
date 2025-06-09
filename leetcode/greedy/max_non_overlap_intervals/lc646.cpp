#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findLongestChain(vector<vector<int>>& pairs) {
            sort(pairs.begin(), pairs.end(), [](vector<int> &p1, vector<int> &p2){
                return p1[1] < p2[1];
            });
    
            int n = pairs.size();
            int res = 0;
            int end = -1001;
            for(int i = 0; i < n; i++){
                if(pairs[i][0] > end){
                    res++;
                    end = pairs[i][1];
                }
            }
            
            return res;
        }
};