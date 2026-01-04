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
        vector<int> v(n);
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            cin >> k;
            mp[k].push_back(i);
        }

        vector<int> res(n);
        bool err = false;
        int curr = 1;
        for(auto it: mp){
            auto &[freq, idx] = it;
            if((idx.size() % freq != 0) || freq > n){
                err = true;
                break;
            }
            
            int cnt = 0;
            for(int i: idx){
                cnt++;
                res[i] = curr;
                if(cnt == freq){
                    cnt = 0;
                    curr++;
                }
            }
        }

        if(err) cout << -1 << nl;
        else{
            for(int r: res) cout << r << " ";
            cout << nl;
        }
	}
}