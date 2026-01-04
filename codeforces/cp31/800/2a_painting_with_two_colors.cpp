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
	int t = 1, n, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		if (b >= a) {
            if(b % 2 == n % 2) yes;
            else no;
            continue;
        }
        if(n % 2 == a % 2 && n % 2 == b % 2) yes;
        else no;

	}
}