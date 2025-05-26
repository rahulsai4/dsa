#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> ka;
        vector<int> depth;
        int mod = (int) 1e9 + 7;
        int maxDepth = 0;
    
        vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
            int n = edges.size() + 1;
            // build tree
            vector<vector<int>> tree(n + 1, vector<int>());
            for(vector<int> &edge : edges){
                int u = edge[0], v = edge[1];
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
            
            // binary lift precomputation
            while((1 << maxDepth) <= n) maxDepth++;         // maxDepth
            ka.resize(n + 1, vector<int>(maxDepth, -1));    // ka
            depth.resize(n + 1, 0);                         // depth initialization
            dfs(tree, 1, -1, 0);                            // dfs for filling depth, ka
    
            // queries
            vector<int> res;
            for(vector<int> &query : queries){
                int u = query[0], v = query[1];
                int uvlca = lca(u, v);                                // lca using binary lift
                int edges = depth[u] + depth[v] - 2 * depth[uvlca];   // edges count using the formula
                int ways = u == v ? 0 : aPowerN(2, edges - 1);        // number of ways using the power function
                res.push_back(ways);
            }
            return res;
        }
    
        int lca(int u, int v){
            // only node with max depth is placed in u
            if(depth[u] < depth[v]){
                swap(u, v);             
            }
    
            // both nodes are taken to same depth by lifting the node with more depth
            // lift u k times
            int k = depth[u] - depth[v]; 
            for(int i = maxDepth - 1; i >= 0; i--){
                if(k & (1 << i)){
                    u = ka[u][i];
                }
            }
    
            // v is the ancestor of u
            if(u == v) return u;
    
            // above lca the nodes are same for all the depths for u, v
            // if depth of u, v = 5, if lca is at depth 3 then if we push both 4 or 5 times we get the same node
            for(int i = maxDepth - 1; i >= 0; i--){
                if(ka[u][i] != ka[v][i]){
                    // same depth different nodes => still haven't reached the lca
                    u = ka[u][i];
                    v = ka[v][i];
                }
            }
    
            // loop stops exactly below the lca
            return ka[u][0];
        }
    
        // power using binary exponentiation
        long long aPowerN(long long a, long long n){
            long long res = 1;
            while(n > 0){
                if(n & 1){
                    res = (res * a) % mod;
                }
                n = n >> 1;
                a = (a * a) % mod;
            }
            return res;
        }
    
        // dfs function to fill the depth and ka
        void dfs(vector<vector<int>> &tree, int node, int par, int d){
            // direct parent
            ka[node][0] = par;
            depth[node] = d;
    
            // other ancestors
            for(int i = 1; i < maxDepth; i++){
                int next = ka[node][i - 1];
                // no further ancestors
                if(next == -1) break;
                ka[node][i] = ka[next][i - 1];
            }
    
            for(int neigh : tree[node]){
                if(neigh != par){
                    dfs(tree, neigh, node, d + 1);
                }
            }
        }
};