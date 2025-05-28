#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int log;
        vector<int> depth;
        vector<vector<int>> ka;
        vector<vector<int>> costs;
        vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    
            vector<vector<pair<int, int>>> tree(n, vector<pair<int, int>>());
            for(vector<int> &edge : edges){
                int u = edge[0], v = edge[1], wt = edge[2];
                tree[u].push_back({v, wt});
                tree[v].push_back({u, wt});
            }
    
            log = 32 - __builtin_clz(n);
            depth.resize(n, 0);
            ka.resize(n, vector<int>(log, -1));
            costs.resize(n, vector<int>(27, 0));
            vector<int> freq(27, 0);
            dfs(tree, 0, -1, 0, freq);
    
            vector<int> res;
            for(vector<int> &query : queries){
                int u = query[0], v = query[1];
                int uvlca = lca(u, v);
                int maxFreq = 0;
                int totalFreq = 0;
                for(int i = 1; i < 27; i++){
                    int curr = costs[u][i] + costs[v][i] - (2 * costs[uvlca][i]);
                    totalFreq += curr;
                    maxFreq = max(maxFreq, curr);
                }
                res.push_back(totalFreq - maxFreq);
            }
            return res;
        }   
    
        int lca(int u, int v){
            if(depth[v] > depth[u]) 
                swap(u, v);
            
            int k = depth[u] - depth[v];
            for(int i = log - 1; i >= 0; i--){
                if(k & (1 << i)){
                    u = ka[u][i];
                }
            }
    
            if(u == v) return u;
    
            for(int i = log - 1; i >= 0; i--){
                if(ka[u][i] != ka[v][i]){
                    u = ka[u][i];
                    v = ka[v][i];
                }
            }
    
            return ka[u][0];
        }
    
        void dfs(vector<vector<pair<int, int>>> &tree, int node, int par, int d, vector<int> &freq){
            costs[node] = freq;
            depth[node] = d;
            ka[node][0] = par;
            for(int i = 1; i < log; i++){
                int curr = ka[node][i - 1];
                if(curr == -1) 
                    break;
                ka[node][i] = ka[curr][i - 1];
            }
    
            for(auto &[child, wt] : tree[node]){
                if(child == par) 
                    continue;
                
                freq[wt]++;
                dfs(tree, child, node, d + 1, freq);
                freq[wt]--;
            }
        }
    };