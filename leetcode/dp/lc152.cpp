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
        int maxProduct(vector<int>& nums) {
            /*
                all positive => first traversal
                contains negative
                    even number of negatives => first traversal
                    odd number of negatives 
                        exclude 1 from left => first traversal, second traversal
                        exclude 1 from right => first traversal, second traversal
                zero => restart the product
            */
            long long res = nums[0];
            long long p = 1;
            for(int i = 0; i < nums.size(); i++){
                p *= nums[i];
                res = max(res, p); 
                if(nums[i] == 0) p = 1;
            }
    
            p = 1;
            for(int i = nums.size() - 1; i >= 0; i--){
                p *= nums[i];
                res = max(res, p);
                if(nums[i] == 0) p = 1;
            }
    
            return res;
        }
};