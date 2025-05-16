#include <bits/stdc++.h>
using namespace std;

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;

class Solution {
    public:
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            set<string> words(wordDict.begin(), wordDict.end());
            int n = s.length();
            vector<vector<string>> dp(n + 1, vector<string>());
            dp[n].push_back("");
    
            helper(s, s.size(), 0, words, dp);
    
            return dp[0];
        }
        vector<string> helper(string &s, int n, int start, set<string> &words, vector<vector<string>> &dp){
            if(dp[start].size() != 0) return dp[start];
    
            string ss;
            vector<string> res;
            for(int end = start; end < n; end++){
                ss += s[end];
                if(words.count(ss)){
                    vector<string> subproblems = helper(s, n, end + 1, words, dp);
                    for(string subproblem_string : subproblems){
                        string curr = ss;
                        if(subproblem_string == "") res.push_back(curr);
                        else res.push_back(curr + " " + subproblem_string);
                    }
                }
            }
    
            return dp[start] = res;
        }
};