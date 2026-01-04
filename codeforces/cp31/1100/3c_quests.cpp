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

void solve(int n, int k, vi &a, vi &b) {
	int res = 0;
	int maxi = 0;
	int l1 = 0, l2;
	for (int i = 0; i < n && i < k; i++) {
		l1 += a[i];
		res = max(res, l1);
		maxi = max(maxi, b[i]);

		int left = (k - i - 1);
		if (left <= 0) {
			break;
		}

		l2 = left * maxi;
		res = max(res, l1 + l2);
	}
	cout << res << nl;
}

int main() {
	fast_io;
	int t = 1, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vi a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		solve(n, k, a, b);
	}
}