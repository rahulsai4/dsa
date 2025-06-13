#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string getPermutation(int n, int k) {
            int fact[10] = {};
            fact[0] = 1;
            for(int i = 1; i <= 9; i++){
                fact[i] = fact[i - 1];
                fact[i] *= i;
            }
            
            set<int> s;
            for(int i = 1; i <= n; i++) s.insert(i);
            int res = 0;
            k--;
            for(int i = 1; i <= n; i++){
                int eachSteps = fact[n - i];
                int numberToSkip = k / eachSteps;
                
                
                auto fixNum = s.begin();
                for(int j = 1; j <= numberToSkip; j++)
                    ++fixNum;
                res *= 10;
                res += *fixNum;
                s.erase(fixNum);
    
                k -= eachSteps * numberToSkip;
            }
    
            return to_string(res);
        }
};