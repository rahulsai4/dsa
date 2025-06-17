#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define nl "\n"
#define all(x) (x).begin(), (x).end()
#define yes cout << \"YES\" << nl
#define no cout << \"NO\" << nl

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
    int t = 1, n, pos;
    cin >> t;
    while(t--) {
        cin >> n >> pos;
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;

            maxi = max(maxi, num);
            mini = min(mini, num);
        }

        int res = 0;
        if(mini < pos && pos < maxi){
            int total = maxi - mini;
            res = min(pos - mini, maxi - pos) + total;
        }
        else if(maxi <= pos){
            res = pos - mini;
        }
        else if(mini >= pos){
            res = maxi - pos;
        }
        cout << (res) << endl;
    }
}