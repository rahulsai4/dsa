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
    int t = 1, n, k, b, s;
    cin >> t;
    while(t--) {
        cin >> n >> k >> b >> s;
        vector<int> res(n, 0);
        int j = n - 1;
        while(j >= 0) {
            int curr = b * k + (k - 1);
            if(curr > s){
                res[j] = s;
                s = 0;
                break;
            }
            else{
                res[j] = curr;
                s -= curr;
                b -= (curr / k);
            }
            j--;
        }
        if(s > 0) cout << -1 << nl;
        else{
            for(int r : res) cout << r << " ";
            cout << nl;
        }
    }
}