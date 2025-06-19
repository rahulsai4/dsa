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
    cin >> t;
    while(t--) {
        cin >> n;
        vi a(n);
        vi b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        
        vector<pair<int, int>> res;
        // a
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - 1; j++){
                if(a[j] > a[j + 1]){
                    swap(a[j], a[j + 1]);
                    res.push_back({1, j + 1});
                }
            }   
        }
        // b
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - 1; j++){
                if(b[j] > b[j + 1]){
                    swap(b[j], b[j + 1]);
                    res.push_back({2, j + 1});
                }
            }   
        }
        // swap
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                res.push_back({3, i + 1});
            }
        }

        cout << res.size() << endl;
        for(auto &[opr, idx] : res){
            cout << opr << " " << idx << nl;
        }
    }
}