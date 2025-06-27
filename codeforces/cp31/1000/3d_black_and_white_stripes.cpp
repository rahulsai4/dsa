#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
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

int main()
{
    fast_io;
    int t = 1, n, k;
    string s;
    cin >> t;
    while (t--){
        cin >> n >> k;
        cin >> s;
        
        // sliding window of window size k
        int res = k;
        int wcnt = 0;
        for(int i = 0, j = 0; j < n; j++){
            wcnt += (s[j] == 'W');
            
            if(j - i + 1 > k){
                wcnt -= (s[i] == 'W');
                i++;
            }
            if(j - i + 1 == k){
                res = min(res, wcnt);
            }
        }
        

        cout << res << nl;
    }
}