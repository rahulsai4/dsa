#include<bits/stdc++.h>
using namespace std;

#define lli long long
int MOD = (int) 1e9 + 7;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    vector<long long> dp(k + 1, 0);
    dp[0] = 1;
    for(int coin : coins){
        for(int weight = coin; weight <= k; weight++){
            if(weight - coin >= 0){
                dp[weight] += dp[weight - coin];
                if(dp[weight] >= MOD){
                    dp[weight] -= MOD;
                }
            }
        }
    }

    cout << dp[k] << endl;
}