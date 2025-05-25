#include <bits/stdc++.h>
using namespace std;

// solution 1 using dfs + dp
class Solution1 {
    public:
        int maxDepth = 0;
        int mod = (int) 1e9 + 7;
        int assignEdgeWeights(vector<vector<int>>& edges) {
            int n = edges.size() + 1;
            vector<vector<int>> tree(n + 1, vector<int>());
            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
            dfs(tree, 1, -1, 0);
    
            vector<long long> odd(maxDepth + 1, 0);
            vector<long long> even(maxDepth + 1, 0);
            odd[1] = 1;
            even[1] = 1;
            for(int i = 2; i <= maxDepth; i++){
                odd[i] = (odd[i - 1] + even[i - 1]) % mod;
                even[i] = (even[i - 1] + odd[i - 1]) % mod;
            }
            return odd[maxDepth];
        }
    
        void dfs(vector<vector<int>> &tree, int node, int par, int d){
            maxDepth = max(maxDepth, d);
    
            for(int n : tree[node]){
                if(n != par) dfs(tree, n, node, d + 1);
            }
        }
};

// solution 2 using dfs + a power n with mod
class Solution2 {
    public:
        int maxDepth = 0;
        int mod = (int) 1e9 + 7;
        int assignEdgeWeights(vector<vector<int>>& edges) {
            int n = edges.size() + 1;
            vector<vector<int>> tree(n + 1, vector<int>());
            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
            dfs(tree, 1, -1, 0);
    
            return aPowerN(2, maxDepth - 1);
        }
    
        void dfs(vector<vector<int>> &tree, int node, int par, int d){
            maxDepth = max(maxDepth, d);
            for(int n : tree[node]){
                if(n != par) 
                    dfs(tree, n, node, d + 1);
            }
        }
    
        long long aPowerN(long long a, long long n){
            long long res = 1;
            while(n > 0){
                if(n & 1){
                    res = (res * a) % mod;
                }
                a = (a * a) % mod;
                n = n >> 1;
            }
            return res;
        }
};
