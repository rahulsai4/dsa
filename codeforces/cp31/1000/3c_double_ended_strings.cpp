#include <bits/stdc++.h>
using namespace std;

#define fast_io                                                                \
	ios::sync_with_stdio(false);                                               \
	cin.tie(nullptr)
#define nl "\n"
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES" << nl
#define no cout << "NO" << nl

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const int MOD = 1e9 + 7;

int lcs(string &s, string &t, int n, int m){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
                res = max(res, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return res;
}

int main() {
	fast_io;
	int t = 1, n;
	string a, b;
	cin >> t;
	while (t--) {
        cin >> a >> b;
        int n = a.length();
        int m = b.length();
        
        int len = lcs(a, b, n, m);

        int res = n - len + m - len;
        cout << res << nl;
	}
}