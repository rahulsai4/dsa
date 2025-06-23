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
    int t = 1, n, d;
    while(t--) {
        cin >> n >> d;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());

        int res = 0;
        int i = 0, j = n - 1;
        while(i <= j) {
            int maxi = v[j];
            int need_count = d % maxi == 0 ? 
                            (d / maxi + 1) : 
                            ceil(d / (double) maxi);
            if(j - i + 1 < need_count) break;

            j--;
            i += (need_count - 1);
            res++;
        }

        cout << res << nl;
    }
}