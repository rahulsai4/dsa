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
	int t = 1, n, m;
	string x, s;
	cin >> t;
	while (t--) {
		cin >> n >> m >> x >> s;
        int i;
		for (i = 0; i < 6; i++) {
            if(x.find(s) != string::npos){
                break;
            }
            x += x;
		}
        if(i == 6) cout << -1 << nl;
        else cout << i << nl;
	}
}