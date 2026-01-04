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
        vector<int> v;
        for(int i = 0; i < n; i++){
            cin >> k;
            if(k == 0) v.push_back(i);
        }
        
        // sub arrays that do not contain 0;
        int cnt = 0;
        int prev = -1;
        for(int pos: v){
            if(pos != prev + 1){
                cnt++;
            }
            prev = pos;
        }
        if(prev != n - 1) cnt++;

        cout << min(cnt, 2) << nl;
	}
}