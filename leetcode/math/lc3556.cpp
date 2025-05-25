#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long sumOfLargestPrimes(string s) {
            int n = s.length();
    
            set<long long> ps;
            for (int i = 0; i < n; i++) {
                long long num = 0;
                for (int j = i; j < n; j++) {
                    num *= 10;
                    num += (s[j] - '0');
    
                    if (isPrime(num)) {
                        ps.insert(num);
                        if(ps.size() > 3) ps.erase(ps.begin());
                    }
                }
            }
    
            long long res = 0;
            for(long long num : ps) res += num;
            return res;
        }
    
        bool isPrime(long long num){
            if(num < 2) return false;
            if(num == 2) return true;
            if(num % 2 == 0) return false;
            int until = sqrt(num);
            for(int i = 3; i <= until; i += 2){
                if(num % i == 0) return false;
            }
            return true;
        }
};