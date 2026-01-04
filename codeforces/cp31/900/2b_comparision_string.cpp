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
	string s;
	cin >> t;
	while (t--) {
        cin >> n >> s;
        
        int len = 1;
        for(int start = 0, end = 1; end < n; end++){
            if(s[end] != s[end - 1]){
                start = end;
            }
            len = max(len, end - start + 1);
        }
        cout << (len + 1) << endl;
    }
}