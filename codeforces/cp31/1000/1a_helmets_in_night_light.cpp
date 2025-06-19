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
    int t = 1, n, p;
    cin >> t;
    while(t--) {
        cin >> n >> p;
        vi a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        auto orderByPrice = [&](const int i, const int j){
            return b[i] == b[j] ? a[i] < a[j] : b[i] > b[j];
        };
        priority_queue<int, vector<int>, decltype(orderByPrice)> v(orderByPrice);
        for(int i = 0; i < n; i++) v.push(i);
        
        
        int left = n;
        queue<int> q;
        long long cost = p;
        q.push(v.top());
        v.pop();

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            left--;

            if(b[curr] >= p) continue;

            while(!v.empty() && a[curr] > 0){
                q.push(v.top());
                v.pop();
                cost += b[curr];
                a[curr]--;
            }
        }

        cost += (1LL * left * p);

        cout << cost << nl; 
    }
}
