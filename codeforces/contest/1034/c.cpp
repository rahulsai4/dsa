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
	int t = 1, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vi v(n);
		string res = "";
		for (int i = 0; i < n; i++) {
			cin >> v[i];
            res += '0';
		}
        
        
        int mini = 1e7;
        int maxi = 0;
		for (int i = 0; i < n; i++) {
            mini = min(mini, v[i]);
            if(v[i] == mini) res[i] = '1';

            maxi = max(maxi, v[n - i - 1]);
            if(v[n - i - 1] == maxi) res[n - i - 1] = '1';
		}

        cout << res << nl;
	}
}