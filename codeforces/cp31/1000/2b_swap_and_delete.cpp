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
    string b;
    cin >> t;
    while(t--) {
        cin >> b;
        int cnt0 = 0;
        int cnt1 = 0;

        for(char c : b) {
            c == '1' ? cnt1++ : cnt0++;
        }

        int res = 0;
        int i = 0;
        int j = 0;
        while(j < b.length()) {
            if(b[i] == '1') {
                if(cnt0 > 0) {
                    cnt0--;
                    i++;
                } else res++;
            } else {
                if(cnt1 > 0) {
                    cnt1--;
                    i++;
                } else res++;
            }
            j++;
        }

        cout << res << nl;
    }
}