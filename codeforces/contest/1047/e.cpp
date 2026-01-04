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

int ffm(vi &v){
    int first_missing = 0;
	for (int i : v) {
		if (i == first_missing) {
			first_missing++;
		} else if (i > first_missing) {
			break;
		}
	}
    return first_missing;
}

void perform_opr(vi &v){
    int n = v.size();

    int first_missing = ffm(v);

    map<int, int> mp;
	for (int i = 0; i < n; i++) {
		if (v[i] > first_missing) {
			v[i] = first_missing;
		}
		mp[v[i]]++;
	}

    for(auto &[i, freq]: mp){
        if(i == first_missing) break;

        if(freq > 1){
            mp[first_missing] += freq;
            mp[i] = 0;
        }
    }

    int idx = 0;
    for(auto [i, freq]: mp){
        while(freq--)
            v[idx++] = i;
    }

}
int main() {
	fast_io;
	ll t = 1, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vi v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(all(v));

        int safety = 30;
        vi prev(0), prevprev(0);
        while(k--){
            perform_opr(v);
            prevprev = prev;
            prev = v;

            if(prevprev.size() && v == prevprev) break;
        }
        
        ll res = 0;
        if(k <= 0){
            res = accumulate(all(v), 0);
        }
        else{
            ll fm = ffm(v);
            map<int, int> freq;
            for(int i: v) freq[i]++;

            for(auto &[i, f]: freq){
                if(f == 1) res += i;
                else{
                    if(k % 2) res += (1LL * fm * f);
                    else res += (1LL * i * f);
                }
            }

        }

        cout << res << nl;
	}
}