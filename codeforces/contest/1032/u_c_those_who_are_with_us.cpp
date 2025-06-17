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
    int t = 1, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vvi grid(n + 1, vi(m + 1));
        int maxi = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> grid[i][j];
                maxi = max(maxi, grid[i][j]);
            }
        }

        vi row(n + 1), col(m + 1);
        int maxi_count = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(grid[i][j] == maxi){
                    maxi_count++;
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int res = maxi;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int curr_cnt = row[i] + col[j] - (grid[i][j] == maxi);
                if(curr_cnt == maxi_count){
                    res = maxi - 1;
                    break;
                }
            }
            if(res == maxi - 1) break;
        }

        cout << res << nl;
    }
}
