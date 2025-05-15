#include<bits/stdc++.h>
using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if(n == 0) return 1;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 10;
    int p = 9;
    int curr = 9;
    for(int i = 2; i <= n; i++){
        dp[i] += dp[i - 1];
        p = p * curr;
        dp[i] += p;
        curr--;
    }
    return dp[n];
}