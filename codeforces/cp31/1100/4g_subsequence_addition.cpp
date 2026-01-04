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
	vi a(n);
	for (auto &x : a)
		cin >> x;
	sort(all(a));

    if(a[0] != 1){
        no;
        return;
    }

	ll reach = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] > reach) {
			no;
			return;
		}
		reach += a[i];
	}
	yes;
}

int main() {
	fast_io;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
}