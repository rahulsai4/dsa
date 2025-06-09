#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> res;
        vector<int> lexicalOrder(int n) {
            helper(n);
            return res;
        }
    
        void helper(int n, long long curr = 0){
            if(curr > n) return;
            if(curr != 0) res.push_back(curr);
    
            curr *= 10;
            if(curr != 0) helper(n, curr);
            for(int i = 1; i <= 9; i++){
                helper(n, curr + i);
            }
        }
};