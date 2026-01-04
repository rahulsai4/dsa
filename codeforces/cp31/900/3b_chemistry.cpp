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
	string s;
    int freq[26];
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cin >> s;
        memset(freq, 0, sizeof(freq));

        for(char c: s) freq[c - 'a']++;

        int oc = 0, ec = 0;
        for(int i = 0; i < 26; i++){
            ((freq[i]) && freq[i] % 2) ? oc++ : ec++;
        }
        
        if(k == 0 && oc > 1) no;
        else if(k < (oc - 1) || k > n) no;
        else yes;
	}
}