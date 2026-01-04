#include <bits/stdc++.h>
using namespace std;

#define fast_io                                                                \
	ios::sync_with_stdio(false);                                               \
	cin.tie(nullptr)
#define nl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define pb push_back
#define ff first
#define ss second

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;

void solve() {
	int n, q;
	cin >> n >> q;
	vi a(n), b(q);
	for (auto &x : a)
		cin >> x;
	for (auto &x : b)
		cin >> x;


    // buckets
    vvi buckets(31);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 31; j++){
            if(a[i] & (1 << j)){
                buckets[j].push_back(i);
                break;
            }
        }
    }

    for(int &x: b){
        for(int i = x; i < 31; i++){
            for(int idx: buckets[i]){
                a[idx] += (1 << (x - 1));
                buckets[x - 1].push_back(idx);
            }
            buckets[i].clear();
        }
    }

    for(int &x: a) cout << x << " ";
    cout << nl;
}

int main() {
	fast_io;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
}