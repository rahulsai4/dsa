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
    int t = 1, n, k, num;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vi nums(n);
        int mini = INT_MAX;
        int even = 0;
        for(int i = 0; i < n; i++) {
            cin >> num;

            if(num % 2 == 0) even++;

            if(num % k == 0){
                mini = 0;
            }
            else{
                int need = (ceil(num / (float) k) * k) - num;
                mini = min(mini, need);
            }
        }
        if(k == 4){
            if(even >= 2) mini = 0;
            else mini = min(mini, 2 - even);
        }
        cout << mini << nl;
    }
}