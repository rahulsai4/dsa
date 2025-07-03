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
	int t = 1, n, m, num;
	cin >> t;
	while (t--) {
		cin >> n >> m;

        vi v;
        for(int i = 0; i < n * m; i++){
            cin >> num;
            v.push_back(num);
        }
        sort(all(v));

        int neg_cnt = 0;
        int max_neg = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] < 0){
                neg_cnt++;
                max_neg = i;
            }
        }
        
        int res = 0;
        for(int &num : v) res += abs(num);

        if(neg_cnt % 2 != 0){
            int neg_res = res;
            neg_res += (2 * v[max_neg]);
            
            int pos_res = 0;
            if(max_neg + 1 < v.size()){
                pos_res = res;
                pos_res -= (2 * v[max_neg + 1]);
            }

            res = max(pos_res, neg_res);
        }

        cout << res << nl;

    }
}