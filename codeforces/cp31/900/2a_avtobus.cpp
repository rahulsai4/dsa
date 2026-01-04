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
	ll t = 1, n;
	cin >> t;
	while (t--) {
		cin >> n;
        ll temp = n;
        bool c1 = (n - 4 * (n / 4)) % 6 == 0;
        bool c2 = (n - 6 * (n / 6)) % 4 == 0;
        if(!c1 && !c2){
            cout << -1 << nl;
            continue;
        }

        ll cnt1 = (n / 4) + (n - 4 * (n / 4)) / 6;
        ll cnt2 = (n / 6) + (n - 6 * (n / 6)) / 4;
        if(c1 && c2){
            cout << min(cnt1, cnt2) << " " << max(cnt1, cnt2) << nl;
        }
        else if(c1){
            cout << cnt1 << " " << cnt1 << nl;
        }
        else{
            cout << cnt2 << " " << cnt2 << nl;
        }
	}
}