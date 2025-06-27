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

int main(){
    fast_io;
    int t = 1, n, r, b;
    cin >> t;
    while (t--){
        cin >> n >> r >> b;
        
        int res = -1;
        int lo = 1;
        int hi = r;
        while(lo <= hi){
            int mid = (lo + hi) / 2;

            bool possible = true;
            
            int blue_need = r / mid;
            if(b < blue_need){
                possible = false;
            }
            if(b > ((blue_need + 1) * mid)){
                possible = false;
            }

            if(possible){
                res = mid;
                hi = lo - 1;
            }
            else{
                lo = hi + 1;
            }

        }
    }
}