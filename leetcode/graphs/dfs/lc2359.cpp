#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int closestMeetingNode(vector<int>& edges, int node1, int node2) {
            int n = edges.size();
    
            vector<int> dist1 = dfs(edges, n, node1);
            vector<int> dist2 = dfs(edges, n, node2);
    
            int res = -1;
            int resDist = INT_MAX;
            for(int i = 0; i < n; i++){
                if(max(dist1[i], dist2[i]) < resDist){
                    res = i;
                    resDist = max(dist1[i], dist2[i]);
                }
            }
    
            return res;
        }
    
        vector<int> dfs(vector<int>& edges, int n, int node){
            vector<int> dist(n, INT_MAX);
            int d = 0;
            while(node != -1 && dist[node] == INT_MAX){
                dist[node] = d;
                node = edges[node];
                d++;
            }
            return dist;
        }
};