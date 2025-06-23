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
    int t = 1, n, k, q;
    cin >> t;
    while(t--) {
        // sliding window of width atleast k
        cin >> n >> k >> q;
        vector<int> temp(n);
        for(int i = 0; i < n; i++) cin >> temp[i];
        
        long long res = 0;
        int j = 0, i = 0;
        while(i < n && j < n){
            while(j < n && temp[j] <= q) j++;
            long long len = j - i;
            if(len >= k){
                long long cnt = (len - k + 1) * (len - k + 2) / 2;
                res += cnt;
            }
            if(i == j) j++;
            i = j;
        }

        cout << res << nl;
    }
}