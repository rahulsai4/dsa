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
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

        if(n == 1){
            cout << v[0] << nl;
            continue;
        }
        
        if(v[0] == 1) v[0] = 2;

		for (int i = 1; i < n; i++) {
            if(v[i] == 1 && i != n - 1) v[i] = 2;
			if (v[i] % v[i - 1] == 0) {
				v[i]++;
			}
		}

		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
		cout << nl;
	}
}