#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define nl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const int MOD = 1e9 + 7;

bool isLucky(int num){
    while(num > 0){
        int m = num % 10;
        if(m != 4 && m != 7) return false;
        num /= 10;
    }
    return true;
}

int main() {
   fast_io;
   int t = 1, n, m, k, l;
   while (t--) {
       cin >> n;
       bool res = false;
       for(int i = 4; i <= n; i++){
            if(n % i == 0 && isLucky(i)){
                res = true;
                break;
            }
       }

       if(res) cout << "YES" << endl;
       else cout << "NO" << endl;
   }
}