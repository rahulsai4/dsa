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
    int t = 1, n, x;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        int i = 0, j = 0;
        int res = 0;
        while(j < n) {
            int small = v[j];
            int big = v[j];

            while(j < n){
                small = min(small, v[j]);
                big = max(big, v[j]);
                if(big <= (small + x) || big <= (small + x + x)){
                    j++;
                }
                else{
                    res++;
                    break;
                }
            }

        }

        cout << res << nl;
    }
}