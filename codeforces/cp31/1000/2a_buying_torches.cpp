#include <bits/stdc++.h>
using namespace std;

#define fast_io                                                                \
	ios::sync_with_stdio(false);                                               \
	cin.tie(nullptr)
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

int64_t ceil_div(int64_t a, int64_t b){
    return (a + b - 1) / b;
}

int main() {
	fast_io;
	int64_t t = 1, x, y, k;
	cin >> t;
	while (t--) {
        cin >> x >> y >> k;
        
        int64_t trades = ceil_div((k * y + k - 1),  x - 1);
        trades += k;
        
        cout << trades << nl;
    }
}