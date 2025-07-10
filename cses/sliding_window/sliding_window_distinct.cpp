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
	ll n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	ll res = 0;
	map<int, int> mp;
	for (int i = 0, j = 0; j < n; j++) {
		mp[v[j]]++;
		if (j - i + 1 == k) {
			cout << mp.size() << " ";
			mp[v[i]]--;
            if(mp[v[i]] == 0) mp.erase(v[i]);
			i++;
		}
	}
    cout << nl;
}

int main() {
	fast_io;
	int t = 1;
	while (t--)
		solve();
}