#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;
        int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
            n = price.size();
            unordered_map<int, int> memo;
            return helper(price, special, needs, memo);
        }
    
        long long helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<int, int> &memo){
    
            int mask = maskNeeds(needs);
            if(mask == 0) return 0;
            if(memo.count(mask)) return memo[mask];
    
            // price
            long long res = 0;
            for(int i = 0; i < n; i++){
                res += (needs[i] * price[i]);
            }
    
            // special
            for(vector<int> offer: special){
                bool use = true;
                for(int i = 0; i < n; i++){
                    if(offer[i] > needs[i]){
                        use = false;
                        break;
                    }
                }
                if(use){
                    for(int i = 0; i < n; i++) needs[i] -= offer[i];
                    res = min(res, offer[n] + helper(price, special, needs, memo));
                    for(int i = 0; i < n; i++) needs[i] += offer[i];
                }
            }
    
            return memo[mask] = res;
        }
    
        int maskNeeds(vector<int> &needs) {
            int mask = 0;
            for (int i = 0; i < needs.size(); i++) {
                mask |= needs[i] << (4*i);
            }
            return mask;
        }
};