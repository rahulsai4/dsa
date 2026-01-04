#include <bits/stdc++.h>
using namespace std;

#define fast_io                                                                \
	ios::sync_with_stdio(false);                                               \
	cin.tie(nullptr)
#define nl "\n"
#define all(x) (x).begin(), (x).end()
#define yes cout << "Yes" << nl
#define no cout << "No" << nl

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
	int t = 1, n, num;
	cin >> t;
	while (t--) {
		cin >> n;
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> num;
            mp[num]++;
		}

        if(mp.size() == 1) yes;
        else if(mp.size() > 2) no;
        else{
            if(abs(mp.begin()->second - mp.rbegin()->second) <= 1) yes;
            else no;
        }
	}
}