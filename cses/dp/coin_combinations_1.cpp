#include<bits/stdc++.h>
using namespace std;

#define lli long long
int MOD = (int) 1e9 + 7;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());

    vector<long long> dp(k + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= k; i++){
        for(int coin : coins){
            if(i - coin < 0) break;
            dp[i] += dp[i - coin];
            if(dp[i] >= MOD) dp[i] -= MOD;
        }
    }
    
    cout << dp[k] << endl;
}


/*
    TLE -> k * coins
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= k; i++){
        for(int coin : coins){
            if(i - coin < 0) break;
            dp[i] = (1LL * dp[i] + dp[i - coin]) % MOD;
        }
    }
*/

/*
    ONE WAY TO SOLVE -> with all combinations
    for(int i = 1; i <= k; i++){
        for(int coin : coins){
            if(i - coin < 0) break;
            dp[i] += dp[i - coin];
            if(dp[i] >= MOD) dp[i] -= MOD;
        }
    }
*/

/*
    OTHER WAY TO SOLVE -> with unique combinations
    for(int coin : coins){
        for(int weight = 0; weight <= k; weight++){
            if(weight - coin >= 0){
                dp[weight] += dp[weight - coin];
                dp[weight] %= MOD;
            }
        }
    }
*/