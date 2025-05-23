#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;
        int m;
        int calculateMinimumHP(vector<vector<int>>& grid) {
            n = grid.size();
            m = grid[0].size();
    
            int lo = 1;
            int hi = INT_MAX - 1;
            int res = -1;
            while(lo <= hi){
                int mid = (lo + hi) / 2;
    
                if(canReach(grid, mid)){
                    hi = mid - 1;
                    res = mid;
                }
                else{
                    lo = mid + 1;
                }
            }
    
            return res;
        }
    
        bool canReach(vector<vector<int>>& grid, int health){
    
            priority_queue<pair<int, pair<int, int>>> pq;
            vector<vector<int>> dist(n, vector<int>(m, 0));
            pq.push({health + grid[0][0], {0, 0}});
            dist[0][0] = health + grid[0][0];
    
            if(dist[0][0] <= 0) return false;
    
            while(!pq.empty()){
                auto [h, coords] = pq.top();
                auto [i, j] = coords;
                pq.pop();
    
                if(i == n - 1 && j == m - 1) return true;
    
                if(i < n - 1){
                    int newH = h + grid[i + 1][j];
                    if(newH > 0 && newH > dist[i + 1][j]){
                        pq.push({newH, {i + 1, j}});
                        dist[i + 1][j] = newH;
                    }
                }
                if(j < m - 1){
                    int newH = h + grid[i][j + 1];
                    if(newH > 0 && newH > dist[i][j + 1]){
                        pq.push({newH, {i, j + 1}});
                        dist[i][j + 1] = newH;
                    }
                }
    
            }
    
            return false;
        }
};