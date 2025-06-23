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
    int t = 1, n, m, num;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> mini2;
        int most_min = INT_MAX;
        for(int i = 0; i < n; i++){
            cin >> m;
            vector<int> v(m);
            for(int j = 0; j < m; j++) cin >> v[j];
            
            // find min 1 elem
            int min1 = *min_element(all(v));
            most_min = min(min1, most_min);
            // erase min 1 elem
            v.erase(find(all(v), min1));
            // find min 2 elem
            int min2 = *min_element(all(v));
            mini2.push_back(min2);
        }

        // n options each => min1, min2
        // to maximize the result we have to maximize min2 of all
        // to maximize min2 remove the min of all min2 by pushing
        // most min in to the vector with least min2
        // as all the values are > 0 no way decreasing by adding min1
        long long sum = accumulate(all(mini2), 0LL);
        int min_of_min2 = *min_element(all(mini2));

        long long res = sum + most_min - min_of_min2;
        cout << res << nl;
    }
}