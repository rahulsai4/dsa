#include<bits/stdc++.h>
using namespace std;

struct FastIO{
    FastIO(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} FastIO;
#define endl "\n"

void dfs(vector<vector<char>> &grid, int i, int j, int n, int m){
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '#') return;

    grid[i][j] = '#';
    dfs(grid, i + 1, j, n, m);
    dfs(grid, i - 1, j, n, m);
    dfs(grid, i, j + 1, n, m);
    dfs(grid, i, j - 1, n, m);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            grid[i][j] = s[j];
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                dfs(grid, i, j, n, m);
                res++;
            }
        }
    }
    cout << res << endl;
}

