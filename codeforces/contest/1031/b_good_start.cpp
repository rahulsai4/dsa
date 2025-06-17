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
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const int MOD = 1e9 + 7;

int main() {
   fast_io;
   int t = 1, w, h, a, b, x1, y1, x2, y2;
   string s;
   cin >> t;
   while (t--) {
        cin >> w >> h >> a >> b;
        cin >> x1 >> y1 >> x2 >> y2;

        // overlap in w
        bool x_compare = abs(x1 - x2) % a == 0;
        // overlap in l
        bool y_compare = abs(y1 - y2) % b == 0;

        if(x1 == x2){
            if(y_compare) yes;
            else no;
        }
        else if(y1 == y2){
            if(x_compare) yes;
            else no;
        }   
        else{
            if(x_compare || y_compare) yes;
            else no;
        }
   }
}