#include <bits/stdc++.h>
using namespace std;

// solution 1 using hasCycle dfs + dp
class Solution {
    public:
        int res = 0;
        int largestPathValue(string colors, vector<vector<int>>& edges) {
    
            int n = colors.size();
    
            vector<vector<int>> graph(n, vector<int>());
            for(vector<int> &edge : edges){
                graph[edge[0]].push_back(edge[1]);
            }
    
            vector<vector<int>> dp(n, vector<int>(26, 0));
            vector<int> state(n, 0);
            for(int i = 0; i < n; i++){
                if(state[i] == 0){
                    if(dfs(graph, colors, i, state, dp)) return -1;
                }
            }
            return res;
    
        }
    
        bool dfs(vector<vector<int>> &graph, string &colors, int node, vector<int> &state, vector<vector<int>> &dp){
    
            if(state[node] == 1) return true;
            if(state[node] == 2) return false;
    
            state[node] = 1;
    
            for(int neigh : graph[node]){
                if(dfs(graph, colors, neigh, state, dp)) return true;
    
                for(int i = 0; i < 26; i++){
                    dp[node][i] = max(dp[node][i], dp[neigh][i]);
                }
            }
    
            res = max(res, ++dp[node][colors[node] - 'a']);
            state[node] = 2;
            return false;
        }
};

// solution 2 using topological sort + dp
class Solution {
    public:
        bool hasCycle = false;
        int res = -1;
        vector<int> colorMap;
        
        int largestPathValue(string colors, vector<vector<int>>& edges) {
    
            int n = colors.size();
    
            vector<vector<int>> graph(n, vector<int>());
            vector<int> indegree(n, 0);
            for(vector<int> &edge : edges){
                graph[edge[0]].push_back(edge[1]);
                indegree[edge[1]]++;
            }
    
            vector<vector<int>> dp(n, vector<int>(26, 0));
            queue<int> q;
            for(int i = 0; i < n; i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
    
            int vis = 0;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                vis++;
    
                dp[curr][colors[curr] - 'a']++;
    
                res = max(res, dp[curr][colors[curr] - 'a']);
    
                for(int neigh : graph[curr]){
                    for(int i = 0; i < 26; i++){
                        dp[neigh][i] = max(dp[neigh][i], dp[curr][i]);
                    }
                    
                    indegree[neigh]--;
                    if(indegree[neigh] == 0)
                        q.push(neigh);
                }
            }
    
            return vis == n ? res : -1;
        }
};