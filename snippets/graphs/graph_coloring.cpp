#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<int> color(n + 1, -1);
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(!dfs(graph, i, color, 1)){
                cout << "IMPOSSIBLE" << "\n";
                return 0;
            }
        }
    }
}

// must be called with in a for loop
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