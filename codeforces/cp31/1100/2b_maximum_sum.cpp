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

// 1 2 5 6 10

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));

    vll pref(n + 1, 0);
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i - 1];
    }

    ll res = 0;
    for(int maxCnt = 0; maxCnt <= k; maxCnt++){
        int minCnt = (k - maxCnt) * 2;
        ll curr = pref[n - maxCnt] - pref[minCnt];
        res = max(res, curr);
    }

    cout << res << nl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();
}