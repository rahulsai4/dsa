#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
    public:
        vector<vector<int>> dp;
        NumMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            // always use padding
            dp.resize(n + 1, vector<int>(m + 1, 0));
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    // add curr, (i - 1, j), (i, j - 1)
                    // remove (i - 1, j - 1)
                    dp[i][j] = grid[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
                }
            }
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) {
            int rmin = min(row1, row2);
            int rmax = max(row1, row2);
            int cmin = min(col1, col2);
            int cmax = max(col1, col2);
            // these values are from grid not dp so map them to dp then find res;
    
            return dp[rmax + 1][cmax + 1] - dp[rmax + 1][cmin] - dp[rmin][cmax + 1] + dp[rmin][cmin];
        }
};