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
    long long t = 1, n;
    cin >> t;
    while(t--) {
        cin >> n;
        
        bool found = false;
        int a = 1;
        for(long long i = 2; 1LL * i * i <= n; i++){
            if(n % i == 0){
                a = n / i;
                break;
            }
        }
        cout << a << " " << (n - a) << nl;
    }
}