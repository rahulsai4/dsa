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

bool dfs(vector<vector<int>> &graph, int i, vector<int> &color, int curr);

int main() {
    int n, e, u, v;
    cin >> n >> e;
    vector<vector<int>> graph(n + 1, vector<int>());
    for(int i = 0; i < e; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> color(n + 1, -1);
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(!dfs(graph, i, color, 1)){
                cout << "IMPOSSIBLE" << nl;
                return 0;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << color[i] << " ";
    }
    cout << nl;

}

bool dfs(vector<vector<int>> &graph, int i, vector<int> &color, int curr){
    if(color[i] != -1){
        return color[i] == curr;
    }
    
    color[i] = curr;
    int next = curr ^ 3;

    for(int neigh : graph[i]){
        if(!dfs(graph, neigh, color, next)) return false;
    }

    return true;
}