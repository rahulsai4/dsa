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
	ll t = 1, n, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		ll res = LLONG_MAX;

		for (ll add = 0; add < 32; add++) {
			ll new_b = b + add;
			if (new_b == 1)
				continue;

			ll temp_a = a;
			int div = 0;
			while (temp_a) {
				temp_a /= new_b;
				div++;
			}

			res = min(res, add + div);
		}

		cout << res << nl;
	}
}