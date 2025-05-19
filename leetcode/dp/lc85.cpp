#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
    
            int res = 0;
            vector<vector<int>> dp(n + 1, vector<int>(m + 2, 0));
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if(matrix[i - 1][j - 1] == '1'){
                        dp[i][j] = 1 + dp[i - 1][j];
                    }
                }
                res = max(res, largestRectangleInHistogram(dp[i]));
            }
    
            return res;
        }
    
        int largestRectangleInHistogram(vector<int> &hts){
            stack<pair<int, int>> s;
            int res = 0;
            for(int i = 0; i < hts.size(); i++){
                int currHt = hts[i];
                int currInd = i;
                while(!s.empty() && s.top().first > currHt){
                    auto [ht, ind] = s.top();
                    s.pop();
                    int wd = (i - ind);
                    res = max(res, (ht * wd));
                    currInd = ind;
                }
                s.push({currHt, currInd});
            }
            return res;
        }
    };