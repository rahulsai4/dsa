#include <bits/stdc++.h>
using namespace std;

struct FastIO{
    FastIO(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;

using lli = long long;
constexpr char nl = '\n';

void bfs(vector<vector<int>> &graph, int n);

int main() {
    int n, e, u, v;
    cin >> n >> e;
    vector<vector<int>> graph(n + 1, vector<int>());
    for(int i = 0; i < e; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(graph, n);
}

void bfs(vector<vector<int>> &graph, int n){
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    queue<int> q;
    
    q.push(1);
    visited[1] = true;
    int count = 0;
    while(!q.empty()){
        if(parent[n] != -1) break;
        int s = q.size();
        for(int i = 0; i < s; i++){
            int curr = q.front();
            q.pop();    
            if(curr == n) break;
            for(int neighbor : graph[curr]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    parent[neighbor] = curr;
                    q.push(neighbor);
                }
            }
        }
        count++;
    }

    if(parent[n] == -1){
        cout << "IMPOSSIBLE" << nl;
    }
    else{
        stack<int> s;
        int curr = n;
        while(curr != -1){
            s.push(curr);
            curr = parent[curr];
        }
        cout << s.size() << nl;
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
}