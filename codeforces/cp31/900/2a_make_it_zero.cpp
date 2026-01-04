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
	int t = 1, n, k;
	cin >> t;
	while (t--) {
		cin >> n;
        int x = 0;
        for(int i = 0; i < n; i++){
            cin >> k;
            x ^= k;
        }

        if(x == 0){
            cout << 1 << nl;
            cout << 1 << " " << n << nl;
        }
        else{
            if(n % 2 == 0){
                cout << 2 << nl;
				cout << 1 << " " << n << nl;
                cout << 1 << " " << n << nl;
            }
            else{
                cout << 4 << nl;
                cout << 1 << " " << (n - 1) << nl;
                cout << 1 << " " << (n - 1) << nl;
				cout << (n - 1) << " " << n << nl; 
				cout << (n - 1) << " " << n << nl; 
            }
        }
    }
}