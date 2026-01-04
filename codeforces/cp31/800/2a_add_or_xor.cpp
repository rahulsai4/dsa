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
	int t = 1, a, b, x, y;
	cin >> t;
	while (t--) {
		cin >> a >> b >> x >> y;

        int cost = 0;
        if(b < a){
            if(a - b > 1) cout << -1 << nl;
            else if(a - b == 1 && a % 2 == 0) cout << -1 << nl;
            continue;
        }
        if(x <= y){
            cost = (b - a) * x;
        }
        else{
            int odd = (b - a) / 2;
            cost = odd * y + (b - a + 1 - odd) * x;
        }
        cout << cost << nl;
	}
}