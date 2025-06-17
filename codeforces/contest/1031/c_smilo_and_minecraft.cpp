#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define nl "\n"
#define all(x) (x).begin(), (x).end()
#define yes cout << \"YES\" << nl
#define no cout << \"NO\" << nl

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const int MOD = 1e9 + 7;

int n, m, k;
int sum[501][501] = {};

int pref(int x, int y){
    x = min(x, n);
    x = max(0, x);
    y = min(y, m);
    y = max(0, y);

    return sum[x][y];
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        vector<string> grid(n);
        
        int all_gold = 0;

        for(int i = 0; i < n; i++) {
            cin >> grid[i];
            for(char c : grid[i]){
                if(c == 'g') all_gold++;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                sum[i][j] = (grid[i - 1][j - 1] == 'g') + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        
        int min_gold = all_gold;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // empty
                if(grid[i][j] == '.'){
                    // 4 ends of the square
                    int xl = i - k - 1;
                    int xr = i + k;
                    int yt = j - k - 1;
                    int yb = j + k;

                    int gold = pref(xr, yb) - pref(xl, yb) - pref(xr, yt) + pref(xl, yt);
                    min_gold = min(min_gold, gold);
                }
            }
        }

        int res = all_gold - min_gold;
        cout << res << endl;
    }
}