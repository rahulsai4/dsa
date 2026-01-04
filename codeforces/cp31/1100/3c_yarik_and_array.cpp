#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define nl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define pb push_back
#define ff first
#define ss second

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;


#define dbg(x) cerr << #x << " = " << (x) << nl

void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto &x : a) cin >> x;
    
    int res = INT_MIN;
    int i = 0, j = 0;
    while(j < n){
        i = j;
        int expected_parity = !(abs(a[i]) % 2);

        int maxi = a[i];
        int curr = a[i];
        while((j + 1) < n && (abs(a[j + 1]) % 2) == expected_parity){
            j++;
            curr = max(a[j], curr + a[j]);
            maxi = max(maxi, curr);
            expected_parity = !expected_parity;
        }

        res = max(res, maxi);
        j++;
    }
    
    cout << res << nl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();
}