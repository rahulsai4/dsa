#include<bits/stdc++.h>
using namespace std;

#define lli long long
int MOD = (int) 1e9 + 7;

int main(){
    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX - 1);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int temp = i;
        while(temp > 0){
            dp[i] = min(dp[i], 1 + dp[i - temp % 10]);
            temp = temp / 10;
        }
    }
  
    
    cout << dp[n] << endl;
}