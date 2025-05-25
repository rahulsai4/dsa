#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string resultingString(string s) {
            vector<char> v;
            for(char c : s){
                if(v.size() > 0 && (abs(v.back() - c) == 1 || abs(v.back() - c) == 25))
                    v.pop_back();
                else 
                    v.push_back(c);
            }
    
            return string(v.begin(), v.end());
        }
};