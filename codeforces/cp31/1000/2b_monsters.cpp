#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
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

int main() {
    fast_io;
    int t = 1, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            v[i] %= k;
            if(v[i] == 0) v[i] = k;
        }

        vector<int> copy(n);
        iota(all(copy), 0);

        sort(all(copy), [&](const int i, const int j){
            return v[i] == v[j] ? i < j : v[i] > v[j];
        });

        for(int c : copy) cout << c + 1 << " ";
        cout << endl;
    }
}