#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define nl "\n"
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES" << nl
#define no  cout << "NO"  << nl

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
        cin >> n >> s;
        unordered_map<char, int> left, right;
        for(char c : s) right[c]++;

        right[s[0]]--;
        left[s[0]]++;

        int res = 0;

        for(int i = 1; i < n - 1; i++) {
            char c = s[i];
            right[s[i]]--;
            if(right[s[i]] == 0) right.erase(s[i]);
            if(left.find(c) != left.end() || right.find(c) != right.end()) {
                res = 1;
                break;
            }
            left[s[i]]++;

        }

        if(res) yes;
        else no;
    }
}