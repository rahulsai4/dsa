#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool wordBreak(string s, vector<string>& words) {
            unordered_set<string> wordSet(words.begin(), words.end());
            int n = s.length();
            vector<bool> dp(n + 1, false);
            dp[n] = true;
    
            for(int start = n - 1; start >= 0; start--){
                string ss = "";
                for(int end = start; end < n; end++){
                    ss += s[end];
    
                    if(wordSet.count(ss) && dp[end + 1]){
                        dp[start] = true;
                    }
                }
            }
    
            return dp[0];
        }
    /* 
        bool wordBreak(string s, vector<string>& words) {
            unordered_set<string> wordSet(words.begin(), words.end());
            int n = s.length();
            vector<int> dp(n, -1);
    
            return helper(s, 0, n, wordSet, dp);
        }
    
        bool helper(string s, int start, int n, unordered_set<string> &wordSet, vector<int> &dp){
            if(start == n) return true;
    
            if(dp[start] != -1) return dp[start];
            
            string ss;
            for(int end = start; end < n; end++){
                ss += s[end];
                if(wordSet.count(ss)){
                    if(helper(s, end + 1, n, wordSet, dp)) 
                        return true;
                }
            }
    
            return dp[start] = false;
        }
    */
};