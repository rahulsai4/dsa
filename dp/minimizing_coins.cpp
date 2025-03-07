#include<bits/stdc++.h>
using namespace std;

#define lli long long
int MOD = (int) 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    // bottom up
    vector<int> dp(k + 1, INT_MAX - 1);
    dp[0] = 0;
    for(int i = 1; i <= k; i++){
        for(int coin : coins){
            if(i - coin < 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }

    dp[k] = dp[k] == INT_MAX - 1 ? -1 : dp[k];
    cout << dp[k] << endl;
}   