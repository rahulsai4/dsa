#include <bits/stdc++.h>
using namespace std;

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;

#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const int MOD = 1e9 + 7;

int main() {
   int t, n, k;
   cin >> t;
   while(t-- > 0){
        cin >> n >> k;
        string res = "";
        for(int i = 0; i < k; i++) res += '1';
        for(int i = 0; i < n - k; i++) res += '0';
        cout << res << endl;
   }
}