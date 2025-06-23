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
    char c;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> c >> s;
        if(c == 'g') {
            cout << 0 << nl;
            continue;
        }

        vector<int> next(n, -1);
        stack<int> stk;
        int first_g_index = n;
        for(int i = 0; i < n; i++){
            if(s[i] == 'g'){
                first_g_index = min(first_g_index, i);
                next[i] = 0;
                while(!stk.empty()){
                    next[stk.top()] = i;
                    stk.pop();
                }
            }
            else{
                stk.push(i);
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == c){
                if(next[i] != -1){
                    res = max(res, next[i] - i);
                }
                else{
                    res = max(res, n - i + first_g_index);
                }
            }
        }

        cout << res << nl;
    }
}