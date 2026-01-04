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
	int t = 1, n, q, l, r, k, curr;
	cin >> t;
	while (t--) {
        cin >> n >> q;
        vector<int> v(n + 1, 0);
        int sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> curr;
            sum += curr;
            v[i] = v[i - 1] + curr;
        }

        while(q--){
            cin >> l >> r >> k;
            

            int temp = sum - (v[r] - v[l - 1]);
            curr = (r - l + 1) * k;
            temp += curr;

            if(temp % 2) yes;
            else no;
        }
    }
}