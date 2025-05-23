#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;
        int m;
        
        int calculateMinimumHP(vector<vector<int>>& grid) {
            n = grid.size();
            m = grid[0].size();
            vector<vector<int>> dp(n, vector<int>(m, -1));
    
            return minHealthNeeded(grid, 0, 0, dp);
        }
    
        int minHealthNeeded(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
            if(i == n || j == m) return 1e9;
    
            if(i == n - 1 && j == m - 1) 
                return grid[i][j] <= 0 ? -grid[i][j] + 1 : 1;
    
            if(dp[i][j] != -1) return dp[i][j];
    
            int right = minHealthNeeded(grid, i, j + 1, dp);
            int down = minHealthNeeded(grid, i + 1, j, dp);
    
            int res = min(right, down) - grid[i][j];
    
            return dp[i][j] = (res <= 0 ? 1 : res);
        }
};