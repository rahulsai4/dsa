#include<bits/stdc++.h>
using namespace std;

#define lli long long
int MOD = (int) 1e9 + 7;

int generate_ways(int target, vector<int> &dp);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    // bottom up
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i - j < 0) break;
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    cout << dp[n] << endl;
}

// top down
int generate_ways(int target, vector<int> &dp){
    if(target < 0) return 0;
    if(target == 0) return 1;
    if(dp[target] != -1) return dp[target];

    lli res = 0;
    for(int i = 1; i <= 6; i++){
        res = (res + generate_ways(target - i, dp)) % MOD;
    }

    return dp[target] = res;
}
