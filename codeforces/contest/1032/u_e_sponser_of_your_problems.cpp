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
    int t = 1;
    string l, r;
    cin >> t;
    while(t--) {
        cin >> l >> r;
        int n = l.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            int ld = l[i] - '0';
            int rd = r[i] - '0';
            if(ld > rd) swap(ld, rd);

            if(ld == rd) 
                res += 2;
            else if((rd - ld) == 1 || (rd == 9 && ld == 0)) 
                res += 1;
        }
        cout << res << nl;
    }
}