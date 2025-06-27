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
	long long t = 1, w, h, k, pt;
	cin >> t;
	while (t--) {
		long long res = 0;
		cin >> w >> h;
		// 4 sides -> b, t, l, r
		// horizontal
		for (int i = 0; i < 2; i++) {
			cin >> k;
			long long maxi = 0, mini = w;
			while (k--) {
				cin >> pt;
				maxi = max(maxi, pt);
				mini = min(mini, pt);
			}
			res = max(res, h * (maxi - mini));
		}

		// vertical
		for (int i = 0; i < 2; i++) {
			cin >> k;
			long long maxi = 0, mini = h;
			while (k--) {
				cin >> pt;
				maxi = max(maxi, pt);
				mini = min(mini, pt);
			}

			res = max(res, w * (maxi - mini));
		}

		cout << res << nl;
	}
}