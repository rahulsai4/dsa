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

void solve() {
	ll n, k, x, a, b, c;
	cin >> n >> k;
	cin >> x >> a >> b >> c;

	vector<int> v(n);
	v[0] = x;
	for (int i = 1; i < n; i++) {
		v[i] = ((a * v[i - 1]) % c + b) % c;
	}

	ll res = 0;
	ll curr = 0;
	for (int i = 0, j = 0; j < n; j++) {
		curr ^= v[j];
		if (j - i + 1 == k) {
			res ^= curr;
			curr ^= v[i];
			i++;
		}
	}

	cout << res << nl;
}

int main() {
	fast_io;
	int t = 1;
	while (t--)
		solve();
}