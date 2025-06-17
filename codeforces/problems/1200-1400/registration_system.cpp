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

int main() {
   fast_io;
   int t = 1, n, m, k, l;
   string s;
   cin >> t;
   unordered_map<string, int> um;
   while (t--) {
       cin >> s;
       if(um.find(s) != um.end()){
            string new_name = s + to_string(um[s]);
            cout << new_name << nl;
            um[s]++;
       }
       else{
        um[s] = 1;
        cout << "OK" << nl;
       }
   }
}