#include<bits/stdc++.h>
using namespace std;

#define lli long long
int MOD = (int) 1e9 + 7;

int helper(vector<vector<int>> &grid, vector<vector<lli>> &dp, int n, int row, int col);

int main(){
    string s;
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '.') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }

    vector<vector<lli>> dp(n, vector<lli>(n, -1));
    cout << helper(grid, dp, n, n - 1, n - 1) << endl;
}

int helper(vector<vector<int>> &grid, vector<vector<lli>> &dp, int n, int row, int col){
    if(row >= n || col >= n || row < 0 || col < 0 || grid[row][col] == 0) return 0;
    if(row == 0 && col == 0) return 1;

    if(dp[row][col] != -1) return dp[row][col];

    dp[row][col] = helper(grid, dp, n, row - 1, col);
    dp[row][col] += helper(grid, dp, n, row, col - 1);

    if(dp[row][col] >= MOD) dp[row][col] -= MOD;

    return dp[row][col];
}