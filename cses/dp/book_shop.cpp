#include<bits/stdc++.h>
using namespace std;

#define lli long long
int MOD = (int) 1e9 + 7;

int main(){
    int n, x;
    cin >> n >> x;

    int price[n], pages[n];
    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> pages[i];

    int dp[n + 1][x + 1];
    // initialization
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 0; j <= x; j++) dp[0][j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            // include
            if(price[i - 1] <= j){
                dp[i][j] = max(dp[i][j], pages[i - 1] + dp[i - 1][j - price[i - 1]]);
            }
            // exclude
            dp[i][j] = max(dp[i][j] , dp[i - 1][j]);
        }
    }

    cout << dp[n][x] << "\n";
}

// top-down => not accepted
int helper(int n, int x, int price[], int pages[], vector<vector<int>> &dp){
    if(n <= 0 || x <= 0) return 0; 
    if(dp[n][x] != -1) return dp[n][x];

    if(price[n - 1] <= x)
        dp[n][x] = max(dp[n][x], pages[n - 1] + helper(n - 1, x - price[n - 1], price, pages, dp));
    dp[n][x] = max(dp[n][x], helper(n - 1, x, price, pages, dp));

    return dp[n][x];
}