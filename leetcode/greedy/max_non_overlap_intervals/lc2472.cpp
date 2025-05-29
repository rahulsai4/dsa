#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxPalindromes(string s, int k) {
            int n = s.length();
    
            // for each index j of palin
                // store the max index i where s[i: j] is a palindrome
            vector<int> palin(n, INT_MIN);
            vector<pair<int, int>> intervals;
            if(k == 1){
                palin[0] = 0;
            }
            for(int i = 1; i < n; i++){
                expand(s, i, i, palin, k);
                expand(s, i - 1, i, palin, k);
            }
    
            // no overlap intervals pattern with a slight twist
            int res = 0;
            int end = -1;
            int start = 0;
            for(int i = 0; i < n; i++){
                if(palin[i] == INT_MIN) continue;
                if(palin[i] > end){
                    res++;
                    end = i;
                }
            }
            return res;
        }
    
        void expand(string &s, int l, int r, vector<int> &palin, int &k){
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                if(r - l + 1 >= k)
                    palin[r] = max(palin[r], l);
                l--;
                r++;
            }
        }
};