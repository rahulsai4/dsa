#include<bits/stdc++.h>
using namespace std;

struct FastIO{
    FastIO(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} FastIO;
#define endl "\n"

bool bfs(vector<vector<char>> &grid, int i, int j, vector<vector<char>> &parent, map<char, pair<int, int>> dirs){ 
    
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    parent[i][j] = '*';
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        
        for(auto &[move, coords] : dirs){
            int newx = x + coords.first;
            int newy = y + coords.second;
            
            if(newx < 0 || newy < 0 || newx >= n || newy >= m || parent[newx][newy] != '-' || grid[newx][newy] == '#') 
                continue;

            parent[newx][newy] = move;
            if(grid[newx][newy] == 'B') return true;
            q.push({newx, newy});
        }
    }


    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    string s;
    int startI, startJ, endI, endJ;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            grid[i][j] = s[j];
            if(s[j] == 'A'){
                startI = i;
                startJ = j;
            }
            else if(s[j] == 'B'){
                endI = i;
                endJ = j;
            }
        }
    }
    vector<vector<char>> parent(n, vector<char>(m, '-'));
    map<char, pair<int, int>> dirs = {
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'R', {0, 1}},
        {'L', {0, -1}}
    };


    bool res = bfs(grid, startI, startJ, parent, dirs);

    if(res){
        cout << "YES" << endl;
        stack<char> path;
        int i = endI;
        int j = endJ;
        while(parent[i][j] != '*'){
            char curr = parent[i][j];
            path.push(curr);

            if(curr == 'L') j++;
            else if(curr == 'R') j--;
            else if(curr == 'U') i++;
            else i--;
        }
        cout << path.size() << endl;
        while(!path.empty()){
            cout << path.top();
            path.pop();
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

