#include <bits/stdc++.h>
using namespace std;
// solution 1 using 2 pass dfs
class Solution1 {
    public:
        vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
            // tree 2
            auto [odd2, even2] = computeTree(edges2);
            int n = odd2.size();
            int maxi = 0;
            for(int i = 0; i < n; i++){
                maxi = max(maxi, odd2[i]);
            }
    
            vector<int> res;
            // tree 1
            auto [odd1, even1] = computeTree(edges1);
            n = odd1.size();
            for(int i = 0; i < n; i++){
                int curr = maxi + even1[i];
                res.push_back(curr);
            }
            
            return res;
        }
    
        pair<vector<int>, vector<int>> computeTree(vector<vector<int>>& edges){
            int n = edges.size() + 1;
            vector<vector<int>> tree(n, vector<int>());
            for (vector<int>& e : edges) {
                int u = e[0], v = e[1];
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
            vector<int> odd(n, 0);
            vector<int> even(n, 0);
            dfs1(tree, -1, 0, odd, even);
            dfs2(tree, -1, 0, odd, even);
            return {odd, even};
        }
    
        void dfs1(vector<vector<int>> &tree1, int par, int node, vector<int> &odd, vector<int> &even){
            even[node] = 1;
            for(int neigh : tree1[node]){
                if(neigh != par){
                    dfs1(tree1, node, neigh, odd, even);
                    even[node] += odd[neigh];
                    odd[node] += even[neigh];
                }
            }
        }
        void dfs2(vector<vector<int>> &tree1, int par, int node, vector<int> &odd, vector<int> &even){
            if(par != -1){
                int parOddLeft = odd[par] - even[node];
                int parEvenLeft = even[par] - odd[node];
    
                odd[node] += parEvenLeft;
                even[node] += parOddLeft;
            }
    
            for(int neigh : tree1[node]){
                if(neigh != par){
                    dfs2(tree1, node, neigh, odd, even);
                }
            }
        }
};

// solution 2 using parity
class Solution {
    public:
        vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
            // tree 2
            auto [p2, c2] = computeTree(edges2);
            auto &[oc2, ec2] = c2;
            int maxi = max(oc2, ec2);
    
            vector<int> res;
            // tree 1
            auto [p1, c1] = computeTree(edges1);
            auto &[oc1, ec1] = c1;
            for(int i = 0; i < p1.size(); i++){
                int curr = p1[i] ? oc1 : ec1;
                res.push_back(curr + maxi);
            }
            
            return res;
        }
    
        pair<vector<bool>, pair<int, int>> computeTree(vector<vector<int>>& edges){
            int n = edges.size() + 1;
            vector<vector<int>> tree(n, vector<int>());
            for (vector<int>& e : edges) {
                int u = e[0], v = e[1];
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
            vector<bool> parity(n, 0);
            parity[0] = 0;
            dfs(tree, -1, 0, parity);
            int oc = 0, ec = 0;
            for(bool b : parity) b ? oc++ : ec++;
            return {parity, {oc, ec}};
        }
    
        void dfs(vector<vector<int>> &tree1, int par, int node, vector<bool> &parity){
            for(int neigh : tree1[node]){
                if(neigh != par){
                    parity[neigh] = !parity[node];
                    dfs(tree1, node, neigh, parity);
                }
            }
        }
};

// solution 3 => tight
class Solution {
    public:
        vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
            int n = edges1.size() + 1;
            int m = edges2.size() + 1;
    
            vector<vector<int>> tree1 = adjacencyList(edges1);
            vector<vector<int>> tree2 = adjacencyList(edges2);
            vector<bool> parity(n), ignored(m);
            int even2 = dfs(tree2, -1, 0, ignored);
            int odd2 = m - even2;
            int maxi = max(even2, odd2);
            int even1 = dfs(tree1, -1, 0, parity);
            int odd1 = n - even1;
    
            vector<int> res;
            for(int i = 0; i < n; i++){
                int curr = parity[i] ? odd1 : even1;
                res.push_back(curr + maxi);
            }
            return res;
        }
    
        vector<vector<int>> adjacencyList(vector<vector<int>>& edges){
            vector<vector<int>> tree(edges.size() + 1, vector<int>());
            for (vector<int>& e : edges) {
                int u = e[0], v = e[1];
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
            return tree;
        }
    
        int dfs(vector<vector<int>> &tree1, int par, int node, vector<bool> &parity){
            int evenCount = 0;
            if(!parity[node]) evenCount = 1;
            for(int neigh : tree1[node]){
                if(neigh != par){
                    parity[neigh] = !parity[node];
                    evenCount += dfs(tree1, node, neigh, parity);
                }
            }
            return evenCount;
        }
};