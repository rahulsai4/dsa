#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                                   vector<vector<int>>& edges2, int k) {
            int n = edges1.size() + 1;
            int m = edges2.size() + 1;
    
            vector<vector<int>> tree1(n, vector<int>());
            vector<vector<int>> tree2(m, vector<int>());
    
            for (vector<int>& e : edges1) {
                int u = e[0], v = e[1];
                tree1[u].push_back(v);
                tree1[v].push_back(u);
            }
            for (vector<int>& e : edges2) {
                int u = e[0], v = e[1];
                tree2[u].push_back(v);
                tree2[v].push_back(u);
            }
    
            // tree2
            int maxi = 0;
            for (int i = 0; i < m; i++) {
                // send dist as 1 initially to get count of targets <= k - 1
                int curr = dfs(tree2, -1, i, 1, k);
                maxi = max(curr, maxi);
            }
    
            // tree 1
            vector<int> res;
            for(int i = 0; i < n; i++){
                // send dist as 0 initially to get count of targets <= k - 1
                int curr = dfs(tree1, -1, i, 0, k);
                res.push_back(maxi + curr);
            }
    
            return res;
        }
    
        int dfs(vector<vector<int>>& tree, int par, int curr, int d, int k) {
            if (d > k)
                return 0;
            if (d == k)
                return 1;
    
            int res = 1;
            for (int neigh : tree[curr]) {
                if (neigh != par)
                    res += dfs(tree, curr, neigh, d + 1, k);
            }
            return res;
        }
};