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

void solve() {
    ll n, area; cin >> n >> area;
    vll a(n);
    for (auto &x : a) cin >> x;
    
    int res = -1;
    int lo = 1, hi = 1e9;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int w = mid * 2;

        ll ar = 0;
        for(int i = 0; i < n; i++){
            ar += (a[i] + w) * (a[i] + w);
            if(ar > area) break;
        }

        if(ar <= area){
            res = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    cout << res << nl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();
}