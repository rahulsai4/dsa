#include <bits/stdc++.h>
using namespace std;

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;

using lli = long long;
constexpr char nl = '\n';

bool dfs(vector<vector<int>> &graph, int p, int i, vector<bool> &visited, vector<int> &parent, int &sv, int &ev);

int main() {
    int n, e, u, v;
    cin >> n >> e;
    vector<vector<int>> graph(n + 1, vector<int>());
    for(int i = 0; i < e; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    int sv = -1, ev = -1;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(dfs(graph, -1, i, visited, parent, sv, ev)) break;
        }
    }

    if(ev == -1){
        cout << "IMPOSSIBLE" << "\n";
    }
    else{
        vector<int> res;
        int tv = ev;
        while(tv != sv){
            res.push_back(tv);
            tv = parent[tv];
        }
        res.push_back(sv);
        res.push_back(ev);

        cout << res.size() << "\n";
        for(int num : res) cout << num << " ";
        cout << "\n";
    }

}

bool dfs(vector<vector<int>> &graph, int p, int i, vector<bool> &visited, vector<int> &parent, int &sv, int &ev){
    visited[i] = true;
    parent[i] = p;

    for(int neigh : graph[i]){
        if(neigh == p) continue;
        if(visited[neigh]){
            sv = neigh;
            ev = i;
            return true;
        }
        if(dfs(graph, i, neigh, visited, parent, sv, ev)) return true;
    }
    
    return false;
}