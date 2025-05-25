#include <bits/stdc++.h>
using namespace std;

// solution 1 0(n2)
class Solution1 {
    public:
        int longestValidParentheses(string s) {
            int n = s.length();
            vector<int> open(n + 1, 0);
            vector<int> close(n + 1, 0);
    
            int res = 0;
    
            for(int i = 1; i <= n; i++){
                open[i] = open[i - 1];
                close[i] = close[i - 1];
                if(s[i - 1] == '('){
                    open[i]++;
                }
                else{
                    close[i]++;
                    for(int j = i - 1; j > 0; j--){
                        int openWin = open[i] - open[j - 1];
                        int closeWin = close[i] - close[j - 1];
    
                        // ()(() for the last close must break at ( in middle
                        if(openWin > closeWin) break;
                        // ((()))))
                        else if(closeWin > openWin) continue;
    
                        res = max(res, 2 * closeWin);
                    }
                }
            }
    
            return res;
        }
};