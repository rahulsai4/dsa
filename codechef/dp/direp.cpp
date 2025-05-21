#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long helper(string &s, int i, int n, vector<long long> &dp){
    if(i >= n) return 1;
    
    if(dp[i] != -1) return dp[i];
    
    long long res = helper(s, i + 1, n, dp);
    if(i + 3 < n){
        if(s[i] == s[i + 2] && s[i + 1] == s[i + 3] && s[i] != s[i + 1]){
            res = (res + helper(s, i + 3, n, dp)) % mod;
        }
    }
    
    return dp[i] = res;
}

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t-- > 0){
        int n;
        string s;
        cin >> n >> s;
        vector<long long> dp(n, -1);
        
        cout << helper(s, 0, n, dp) << endl;
    }
}
