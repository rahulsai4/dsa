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

ll calcDist(pll &a, pll &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

ll solve() {
	int n, k, a, b;
	cin >> n >> k >> a >> b;
	vector<pll> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first;
		cin >> v[i].second;
	}

	// major city minimum cost
	ll mca = LLONG_MAX, mcb = LLONG_MAX;
	for (int i = 1; i <= k; i++) {
		mca = min(mca, calcDist(v[i], v[a]));
	}
	for (int i = 1; i <= k; i++) {
		mcb = min(mcb, calcDist(v[i], v[b]));
	}   

    ll dis = calcDist(v[a], v[b]);
    return k == 0 ? dis : min(dis, mca + mcb);
}

int main() {
	fast_io;
	int t = 1;
	cin >> t;
	while (t--)
		cout << solve() << nl;
}