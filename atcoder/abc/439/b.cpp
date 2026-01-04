#include <bits/stdc++.h>
using namespace std;

#define fast_io                                                                \
	ios::sync_with_stdio(false);                                               \
	cin.tie(nullptr)
#define nl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define yes cout << "Yes" << nl
#define no cout << "No" << nl
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

int decompose(int n) {
	int res = 0;
	while (n) {
		int d = n % 10;
		res += (d * d);
		n = n / 10;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	unordered_set<int> st;
	while (n > 1 && !st.count(n)) {
		st.insert(n);
		n = decompose(n);
	}

	n == 1 ? yes : no;
}

int main() {
	fast_io;
	int t = 1;
	while (t--)
		solve();
}