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
	int t = 1;
	cin >> t;
	while (t--) {
        int n;
        string s;
    
		cin >> n >> s;

        int bcnt = 0;
        int maxi = 0;
        int i = 0, j = 0;
        while(j < n){
            i = j;

            while(j < n && s[j] == '.'){
                ++j;
                bcnt++;
            }

            maxi = max(maxi, j - i);

            j++;
        }

        if(maxi > 2){
            cout << 2 << nl;
        }
        else{
            cout << bcnt << nl;
        }
	}
}