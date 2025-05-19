#include <bits/stdc++.h>
using namespace std;

// cycle detection => distinct elements
class Solution {
    public:
        int minSwaps(vector<int>& nums) {
            int n = nums.size();
            vector<tuple<int, int, int>> v(n);
            for(int i = 0; i < n; i++){
                int ds = digitSum(nums[i]);
                v[i] = make_tuple(ds, nums[i], i);
            }
    
            sort(v.begin(), v.end());
            vector<bool> vis(n);
            int res = 0;
            for(int i = 0; i < n; i++){
                if(!vis[i]){
                    // curr v[i] index
                    if(get<2>(v[i]) != i){
                        int count = 0;
                        int pos = i;
                        while(!vis[pos]){
                            vis[pos] = true;
                            pos = get<2>(v[pos]);
                            count++;
                        }
                        count = max(count, 0);
                        // count number of elements need count - 1 swaps
                        res += (count - 1);
                    }
                }
            }
    
            return res;
        }
        int digitSum(int num) {
            int s = 0;
            while (num > 0) {
                s += (num % 10);
                num = num / 10;
            }
            return s;
        }
};
