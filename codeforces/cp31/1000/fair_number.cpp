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

bool is_fair(long long n){
    long long temp = n;
    while(temp > 0){
        int d = temp % 10;
        if(d != 0 && n % d != 0) return false;
        temp = temp / 10;
    }
    return true;
}

int main() {
   fast_io;
   long long t = 1, n;
   cin >> t;
   while (t--) {
       cin >> n;
       while(!is_fair(n)) ++n;
       cout << n << nl;
   }
}