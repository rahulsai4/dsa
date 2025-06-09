#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int count = 0;
        int countSubstrings(string s) {
            for(int i = 0; i < s.length(); i++){
                expand(s, i, i);
                expand(s, i, i + 1);
            }
    
            return count;
        }
    
        void expand(string &s, int i, int j){
            while(i >= 0 && j < s.length() && s[i] == s[j]){
                count++;
                i--;
                j++;
            }
        }
};