#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
            if(s.length() < t.length()) return "";
    
            int tl = t.length();
            vector<int> tf(128, 0);
            for(char c : t) tf[c]++;
    
            int resStart = 0;
            int resLen = INT_MAX;
            for(int start = 0, end = 0; end < s.length(); end++){
                if(tf[s[end]] > 0) tl--;
                tf[s[end]]--;
    
                while(tl == 0){
                    if(end - start + 1 < resLen){
                        resStart = start;
                        resLen = end - start + 1;
                    }
    
                    tf[s[start]]++;
                    if(tf[s[start]] > 0) tl++;
                    start++;
                }
            }
    
            return resLen == INT_MAX ? "" : s.substr(resStart, resLen);
        }
};