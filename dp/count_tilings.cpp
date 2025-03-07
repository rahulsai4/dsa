#include<bits/stdc++.h>
using namespace std;

#define lli long long
int MOD = (int) 1e9 + 7;

int fill_2_by_n(int n);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    if(n > m) swap(n, m);
    lli ways = fill_2_by_n(n);

    vector<int> dp(m + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= m; i++){
        // row -> n, col -> m
        if(n % 2 == 0){
            dp[i] = (1L * dp[i] + dp[i - 1]) % MOD;
        } 
        if(i >= 2){
            dp[i] = (1L* dp[i] + (ways * dp[i - 2]) % MOD) % MOD;
        }
    } 

    cout << dp[m] << endl;
}

int fill_2_by_n(int n){
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return n % 2 == 0 ? dp[n] - 1 : dp[n];
}