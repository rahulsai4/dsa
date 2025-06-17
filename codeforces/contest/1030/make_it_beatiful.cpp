#include <bits/stdc++.h>
using namespace std;

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;

#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const int MOD = 1e9 + 7;

int main() {
   ull t, n, k, c;
   ull power[64] = {};
   power[0] = 1;
   for(int i = 1; i < 64; i++){
        power[i] = power[i - 1] * 2; 
   }
   cin >> t;
   while(t-- > 0){
        cin >> n >> k;

        ull res = 0;
        ull freq[64] = {};
        for(int i = 0; i < n; i++){
            cin >> c;
            for(int j = 0; j < 64; j++){
                int bit = c & 1;
                if(bit){
                    res++;
                }
                else{
                    freq[j]++;
                }
                c = c >> 1;
            }
        }
        
        // iterate the freq array 
        for(int i = 0; i < 64; i++){
            unsigned long have = k / power[i];
            if(have == 0) break;
            have = have >= freq[i] ? freq[i] : have;
            
            res += have;
            k -= (have * power[i]);
        }

        cout << res << endl;
        
   }
}