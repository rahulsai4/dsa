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

void solve() {
	int n;
	cin >> n;
	vi arr(n);
	for (auto &a : arr)
		cin >> a;

	long long res = 0;

	// excluding suffix
	unordered_map<int, int> ump;
	for (int &a : arr)
		ump[a]++;
	for (int &a : arr) {
		ump[a]--;
		if (ump[a] == 0)
			ump.erase(a);

		if (a % 5)
			continue;
		int x = a / 5;

		int x7 = ump.count(x * 7) ? ump[x * 7] : 0;
		int x3 = ump.count(x * 3) ? ump[x * 3] : 0;

		res += 1LL * x7 * x3;
	}

	// excluding prefix
	for (int &a : arr) {
        ump[a]++;
		if (a % 5 != 0)
			continue;
		int x = a / 5;

		int x7 = ump.count(x * 7) ? ump[x * 7] : 0;
		int x3 = ump.count(x * 3) ? ump[x * 3] : 0;

		res += 1LL * x7 * x3;

	}
	cout << res << nl;
}

int main() {
	fast_io;
	int t = 1;
	while (t--)
		solve();
}