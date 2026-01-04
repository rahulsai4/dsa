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

ll solveDP(int n, vi& a, vi& b, vi&c) {
    // for all combinations
    vll dpa(n, 0), dpb(n, 0), dpc(n, 0);
    dpa[0] = a[0];
    for(int i = 1; i < n; i++){
        dpa[i] = max(dpa[i - 1], 1LL * a[i]);
    }
    for(int i = 1; i < n; i++){
        dpb[i] = max(dpb[i - 1], b[i] + dpa[i - 1]);
    }
    for(int i = 2; i < n; i++){
        dpc[i] = max(dpc[i - 1], c[i] + dpb[i - 1]);
    }

    return dpc[n - 1];
}

vi top3(int n, vi &a) {
	auto cmp = [&](const int i, const int j) { return a[i] > a[j]; };
	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

	for (int i = 0; i < n; i++) {
		pq.push(i);
		if (pq.size() > 3)
			pq.pop();
	}

	vi res;
	while (!pq.empty()) {
		res.push_back(pq.top());
		pq.pop();
	}
	return res;
}

ll solve(int n, vi& a, vi& b, vi& c){
    // top 3 for all a, b, c
    vi ta = top3(n, a);
    vi tb = top3(n, b);
    vi tc = top3(n, c);

    ll res = 0;
    for(int i: ta){
        for(int j: tb){
            for(int k: tc){
                if(i != j && j != k && i != k){
                    res = max(res, 1LL * a[i] + b[j] + c[k]);
                }
            }
        }
    }

    return res;
}



int main() {
	fast_io;
	int t = 1, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vi a(n), b(n), c(n);
		int cnt = 3;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
        for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
        for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
        
        ll res = solve(n, a, b, c);
        cout << res << endl;
	}
}