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
    string s; cin >> s;
    int n = s.size();

    int res = 0;
    int i = 0, j = 0;
    while(j < n){
        if(s[j] == '1'){
            i = j;
            while(j < n && s[j] == '1') j++;
            int len = j - i - 1;
            res = max({res, len * 2, 1});
        }
        else j++;
    }
    cout << res << nl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();
}