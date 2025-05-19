#include <bits/stdc++.h>
using namespace std;

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;

#define nl endl
#define lli long long

void monsterDfs(vector<string> &grid, int i, int j, vector<vector<int>> &monsterTime, vector<vector<bool>> &mvis, int time);
void printPath(vector<vector<char>> &parent, int i, int j);

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> monsterTime(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> mvis(n, vector<bool>(m, false));
    int sx, sy, ex, ey;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'M'){
                monsterDfs(grid, i, j, monsterTime, mvis, 0);
            }
            else if(grid[i][j] == 'A'){
                sx = i;
                sy = j;
            }
        }
    }

    vector<vector<char>> parent(n, vector<char>(m, '.'));
    map<char, vector<int>> dirs = {{'U', {-1, 0}}, {'D', {1, 0}}, {'R', {0, 1}}, {'L', {0, -1}}};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    queue<pair<int,int>> q;
    pq.push({0, {sx, sy}});
    while(!pq.empty()){ 

        auto [time, coords] = pq.top();
        auto [x, y] = coords;
        pq.pop();

        if(x == 0 || y == 0 || x == n - 1 || y == m - 1){
            parent[sx][sy] = '*';
            cout << "YES" << nl;
            cout << time << nl;
            printPath(parent, x, y);
            return 0;
        }
            
            for(auto &[move, dir] : dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];
    
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                if(grid[nx][ny] == '#') continue;
                if(parent[nx][ny] != '.') continue;
                if(monsterTime[nx][ny] <= time + 1) continue;

                pq.push({time + 1, {nx, ny}});
                parent[nx][ny] = move;
            }

    }
    cout << "NO" << nl;
}

void printPath(vector<vector<char>> &parent, int i, int j){
    stack<char> s;
    while(parent[i][j] != '*'){
        char curr = parent[i][j];
        if(curr == 'U') i++;
        else if(curr == 'D') i--;
        else if(curr == 'R') j--;
        else j++;
        s.push(curr);
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << nl;
}

void monsterDfs(vector<string> &grid, int i, int j, vector<vector<int>> &monsterTime, vector<vector<bool>> &mvis, int time){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].length() || grid[i][j] == '#') return;

    if(time >= monsterTime[i][j]){
        return;
    }

    if(grid[i][j] == 'M' && !mvis[i][j]){
        monsterTime[i][j] = 0;
        mvis[i][j] = true;
        monsterDfs(grid, i, j, monsterTime, mvis, 0);
    }

    monsterTime[i][j] = time;

    monsterDfs(grid, i - 1, j, monsterTime, mvis, time + 1);
    monsterDfs(grid, i + 1, j, monsterTime, mvis, time + 1);
    monsterDfs(grid, i, j - 1, monsterTime, mvis, time + 1);
    monsterDfs(grid, i, j + 1, monsterTime, mvis, time + 1);
}