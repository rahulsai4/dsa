#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minMoves(vector<string>& grid) {
            int n = grid.size();
            int m = grid[0].length();
    
            if(grid[0][0] == '#' || grid[n - 1][m - 1] == '#') return -1;
    
            // neighbors for teleport nodes
            vector<vector<pair<int, int>>> teleport(26, vector<pair<int, int>>());
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] != '.' && grid[i][j] != '#') {
                        teleport[grid[i][j] - 'A'].push_back({i, j});
                    }
                }
            }
    
            // bfs
            vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            vis[0][0] = true;
            // if starting node is a teleport node
            if(grid[0][0] != '.'){
                for(auto &[tx, ty]: teleport[grid[0][0] - 'A']){
                    if(tx == 0 && ty == 0) continue;
                    q.push({tx, ty});
                    vis[tx][ty] = true;
                }
            }
            int d = 0;
            while(!q.empty()){
                int s = q.size();
                for(int i = 0; i < s; i++){
                    auto [x, y] = q.front();
                    q.pop();
    
                    if(x == n - 1 && y == m - 1) return d;
    
                    for(vector<int> &dir : dirs){
                        int nx = x + dir[0];
                        int ny = y + dir[1];
    
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || grid[nx][ny] == '#')
                            continue;
                        
                        char curr = grid[nx][ny];
                        if(curr != '.'){
                            for(auto &[tx, ty] : teleport[curr - 'A']){
                                if(tx == nx && ty == ny) continue;
    
                                q.push({tx, ty});
                                vis[tx][ty] = true;
                            }
                        }
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
                d++;
            }
    
            return -1;
        }
};