#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
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
    int t = 1, n;
    string s;
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;

        map<char, int> right, left;
        for(char c : s) right[c]++;

        int res = 0;
        for(char c : s){
            left[c]++;
            right[c]--;
            if(right[c] == 0) right.erase(c);

            res = max(res, ((int) left.size() + (int) right.size()));
        }
        cout << res << nl;
    }
}