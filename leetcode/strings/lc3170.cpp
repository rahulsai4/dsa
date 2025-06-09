#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string clearStars(string s) {
            int n = s.length();
    
            vector<vector<int>> freq(26, vector<int>());
            for(int i = 0; i < n; i++){
                if(s[i] == '*'){
                    s[i] = '.';
                    for(int j = 0; j < 26; j++){
                        if(!freq[j].empty()){
                            s[freq[j].back()] = '.'; 
                            freq[j].pop_back();
                            break;
                        }
                    }
                }
                else{
                    freq[s[i] - 'a'].push_back(i);
                }
            }
    
            string res = "";
            for(int i = 0; i < n; i++){
                if(s[i] != '.') 
                    res += s[i];
            }
            return res;
        }
};