#include <bits/stdc++.h>
using namespace std;

#define fast_io                                                                \
	ios::sync_with_stdio(false);                                               \
	cin.tie(nullptr)
#define nl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define pb push_back
#define ff first
#define ss second

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << nl
#else
#define dbg(x)
#endif

void solve() {
	int n, k;
	cin >> n;
	vi a(n);
	vll pref(n + 1, 0);
	for (auto &x : a)
		cin >> x;
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + a[i - 1];
	}

	ll res = 0;
	for (int i = 1; i <= (int)sqrt(n); i++) {
		if (n % i == 0) {
			int f = i;
			ll maxi = LLONG_MIN, mini = LLONG_MAX;
			for (int j = f; j <= n; j += f) {
				ll curr = pref[j] - pref[j - f];
				maxi = max(maxi, curr);
				mini = min(mini, curr);
			}
			res = max(res, maxi - mini);

			f = n / i;
			maxi = LLONG_MIN, mini = LLONG_MAX;
			for (int j = f; j <= n; j += f) {
				ll curr = pref[j] - pref[j - f];
				maxi = max(maxi, curr);
				mini = min(mini, curr);
			}
			res = max(res, maxi - mini);
		}
	}

	cout << res << nl;
}

int main() {
	fast_io;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
}