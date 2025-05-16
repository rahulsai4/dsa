#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // longest increasing subsequence
        vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
            int n = words.size();
            vector<int> len(n, 1);
            vector<int> prev(n, -1);
    
            int resPtr = 0;
            for(int i = 0; i < n; i++){
                for(int j = i - 1; j >= 0; j--){
                    if(
                        (len[j] >= len[i]) && 
                        (groups[i] != groups[j]) && 
                        (isValid(words[i], words[j]))
                        ){
                        prev[i] = j;
                        len[i] = len[j] + 1;
                    }
                }
                if(len[i] > len[resPtr]) resPtr = i;
            }
    
            vector<string> res;
            while(resPtr != -1){
                res.push_back(words[resPtr]);
                resPtr = prev[resPtr];
            }
            reverse(res.begin(), res.end());
            return res;
        }
    
        bool isValid(string s1, string s2){
            if(s1.length() != s2.length()) return false;
            int c = 0;
            for(int i = 0; i < s1.length(); i++){
                if(s1[i] != s2[i]) c++;
                if(c == 2) return false;
            }
            return true;
        }
};