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

pair<ll, ll> helper(int temp, int minTemp, int fall){
    int count = (temp - minTemp + fall) / fall;
    count = count < 0 ? 0 : count;
    int afterTemp = temp - (count * fall);
    return {count, afterTemp};
}

int main() {
   fast_io;
   long long t = 1, k, a, b, x, y;
   string s;
   cin >> t;
   while (t--) {
       cin >> k >> a >> b >> x >> y;

       long long res = 0;
       if(a > k){
            auto [count, afterTemp] = helper(k, b, y);
            res = max(res, count);
       }
       else if(b > k){
            auto [count, afterTemp] = helper(k, a, x);
            res = max(res, count);
       }
       else{
            if(true){
                auto [c1, at1] = helper(k, a, x);
                auto [c2, at2] = helper(at1, b, y);
                res = max(res, c1 + c2);
            }
            
            if(true){
                auto [c1, at1] = helper(k, b, y);
                auto [c2, at2] = helper(at1, a, x);
                res = max(res, c1 + c2);
            }
       }

       cout << res << endl;
   }
}