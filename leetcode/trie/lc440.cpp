#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findKthNumber(int n, int k) {
            long long curr = 1;
            k--;
    
            while(k != 0){
                long long steps = calc(n, curr, curr + 1);
                if(k >= steps){
                    k -= steps;
                    curr++;
                }
                else{
                    curr *= 10;
                    k--;
                }
            }
    
            return curr;
        }
    
        long long calc(long long n, long long p1, long long p2){
            long long steps = 0;
            while(p1 <= n){
                steps += min(p2, n + 1) - p1;
                p1 *= 10;
                p2 *= 10;
            }
    
            return steps;
        }
};