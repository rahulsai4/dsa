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
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(all(v));
    
        int max_cnt = 1;
        for(int start = 0, end = 1; end < n; end++){

            if(abs(v[end] - v[end - 1]) > k){
                max_cnt = max(max_cnt, end - start);
                start = end;
            }

            max_cnt = max(max_cnt, end - start + 1);
        }

        
        cout << (n - max_cnt) << nl;
	}
}