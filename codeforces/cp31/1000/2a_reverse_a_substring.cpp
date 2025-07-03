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
	int n;
	string s;
	cin >> n >> s;
	int min_index = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		if(s[i] > s[min_index]){
            yes;
            cout << i + 1 << " " << min_index + 1 << nl;
            return 0;
        }   
        else{
            min_index = i;
        }
	}

    no;
}