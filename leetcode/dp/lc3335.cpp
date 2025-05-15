#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        using lli = long long int;
        int M = (int) 1e9 + 7;
        int lengthAfterTransformations(string s, int t) {
            array<int, 26> freq{};
            for(char c : s) freq[c - 'a']++;
    
            while(t >= 26){
                array<lli, 26> temp{};
                for(int i = 0; i < 25; i++){
                    temp[i] += freq[i];
                    temp[i + 1] += freq[i];
                }
                temp[25] += freq[25];
                temp[0] += freq[25];
                temp[1] += freq[25];
    
                for(int i = 0; i < 26; i++) freq[i] = temp[i] % M; 
    
                t -= 26;
            }
    
            long long res = 0;
            for(int i = 0; i < 26; i++){
                if(i + t > 25){
                    freq[i] = (2 * freq[i]) % M;
                }
                res = (res + freq[i]) % M;
            }
            return res;
        }
        /*
            26 transfromations in single iteration why?
            a -> ab
            b -> bc
            .
            y -> yz
            z -> zab
        */
};