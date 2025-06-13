#include <bits/stdc++.h>
using namespace std;

// simple 3d recursive solution also exists
// space optimized
class Solution {
    public:
        int mod = (int)1e9 + 7;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
        int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
    
            if (maxMove == 0)
                return 0;
    
            int dp[51][51] = {};
            int temp[51][51] = {};
    
            // initialization
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (auto& [x, y] : dirs) {
                        int nx = i + x;
                        int ny = j + y;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            temp[i][j]++;
                    }
                }
            }
    
            long long res = temp[startRow][startColumn];
    
            for (int moves = 2; moves <= maxMove; moves++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        dp[i][j] = 0;
                        for (auto& [x, y] : dirs) {
                            int nx = i + x;
                            int ny = j + y;
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                                continue;
    
                            dp[i][j] = (dp[i][j] + temp[nx][ny]) % mod;
                        }
                    }
                }
    
                res = (res + dp[startRow][startColumn]) % mod;
                memcpy(temp, dp, sizeof(dp));
            }
    
            return res;
        }
    };