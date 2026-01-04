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

ll maxSubArraySum2(vector<int> &arr, int a, int b) {
    int n = arr.size();

	vector<ll> pref(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		pref[i] = arr[i - 1];
		pref[i] += pref[i - 1];
	}
    
    ll res = LLONG_MIN;
    multiset<ll> ms;
    for (int i = a; i <= n; i++) {
        if(i > b) ms.erase(ms.find(pref[i - b - 1]));
        ms.insert(pref[i - a]);
        res = max(res, pref[i] - *ms.begin());
    }

    return res;
}

int main() {
	fast_io;
	ll n, a, b;
	cin >> n >> a >> b;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
	cout << maxSubArraySum2(arr, a, b) << nl;
}