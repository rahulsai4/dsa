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

int main() {
	fast_io;
	ll t = 1, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		ll r1 = a + b;
		ll r2 = a * b + 1;

		if (r1 % 2 && r2 % 2)
			cout << -1 << nl;
		else {
            if(r1 % 2) cout << r2 << nl;
            else if(r2 % 2) cout << r1 << nl;
            else cout << max(r1, r2) << nl;
        }
	}
}