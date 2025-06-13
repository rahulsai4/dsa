#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    int mod = (int) 1e9 + 7;
    cin >> t;

    while(t-- > 0){
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        long long res = 0;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(arr[j] <= arr[i]){
                    dp[i] = (dp[i] + dp[j]) % mod;
                }
            }
            res = (res + dp[i]) % mod;
        }

        cout << res << endl;
    }
}