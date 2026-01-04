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

template <typename T> void printVec(const vector<T> &v) {
	for (const auto &x : v)
		cout << x << " ";
	cout << nl;
}

void solve(int &n, vi &arr) {
	vll temp(n + 1, 0);
    for(int i = 0; i < n; i++){
        temp[i] = arr[i];
    }
    temp[n] = LLONG_MAX;
    sort(all(temp));

	vll pref(temp.size(), 0);
	for (int i = 1; i < pref.size(); i++) {
		pref[i] = temp[i - 1] + pref[i - 1];
	}

	vi res(n);
	for (int i = 0; i < n; i++) {
		ll score = arr[i];

		int prevUb = -1, ub;
		while(1){
			ub = upper_bound(all(temp), score) - temp.begin();
            if(ub == prevUb) break;
			score = pref[ub];
			prevUb = ub;
		}
		res[i] = ub - 1;
	}

	printVec(res);
}

int main() {
	fast_io;
	int t = 1, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vi arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		solve(n, arr);
	}
}
