#include<bits/stdc++.h>
using namespace std;

#define lli long long
int MOD = (int) 1e9 + 7;

long long solve(string s, int i, int r, int c, vector<vector<bool>> &visited, unordered_map<char, pair<int, int>> &um);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    vector<vector<bool>> visited(7, vector<bool>(7, false));
    unordered_map<char, pair<int, int>> um;
    um['U'] = {-1, 0};
    um['D'] = {1, 0};
    um['L'] = {0, -1};
    um['R'] = {0, 1};


    cout << solve(s, 0, 0, 0, visited, um) << '\n';
}

long long solve(string s, int i, int r, int c, vector<vector<bool>> &visited, unordered_map<char, pair<int, int>> &um){
    if(r < 0 || r >= 7 || c < 0 || c >= 7 || visited[r][c]) return 0;
    if(i == 48){
        return r == 6 && c == 0 ? 1 : 0;
    }


    visited[r][c] = true;
    int res = 0;
    if(s[i] == '?'){
        for(auto it : um){
            res += solve(s, i + 1, r + it.second.first, c + it.second.second, visited, um);
        }
    }
    else{
        res = solve(s, i + 1, r + um[s[i]].first, c + um[s[i]].second, visited, um);
    }
    visited[r][c] = false;

    return res;
}