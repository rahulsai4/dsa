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
	vector<int> nums;

	int rt = sqrt(n) + 1;

	for (int i = 1; i <= rt; i++) {
		for (int j = i + 1; j <= rt; j++) {
			long long curr = 1LL * i * i + 1LL * j * j;
			if (curr <= n)
				nums.push_back(curr);
		}
	}

	sort(nums.begin(), nums.end());
	vector<int> res;
	int i = 0, j = 0;
	while (j < nums.size()) {
		i = j;
		while (j + 1 < nums.size() && nums[j + 1] == nums[i])
			j++;
        if(i == j)
		    res.push_back(nums[i]);
		j++;
	}

	cout << res.size() << nl;
	for (int r : res)
		cout << r << " ";
	cout << nl;
}

int main() {
	fast_io;
	int t = 1;
	while (t--)
		solve();
}