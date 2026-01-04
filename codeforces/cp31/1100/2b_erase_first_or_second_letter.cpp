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

void solve(int n, string &s) {
	unordered_map<char, int> mp;
	for (char &c : s)
		mp[c]++;

	ll res = 0;
	for (int i = n - 1; i >= 0; i--) {
        // len = n - i
        // eg. len = 2 _a
        // last char doesn't change but first char varies
		res += mp.size();
		mp[s[i]]--;
		if (mp[s[i]] == 0)
			mp.erase(s[i]);
	}

	cout << res << nl;
}

int main() {
	fast_io;
	int t = 1, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		solve(n, s);
	}
}