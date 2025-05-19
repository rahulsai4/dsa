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
    int n, m, x, y, z;
    cin >> n >> m;
    vector<vector<pll>> graph(n + 1); 

    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        graph[x].push_back({z, y});
    }
    
    vll dist(n + 1, LLONG_MAX);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()){
        auto [ud, u] = pq.top();
        pq.pop();
        if(dist[u] < ud) continue;

        for(auto [vd, v] : graph[u]){
            if(ud + vd < dist[v]){
                dist[v] = ud + vd;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout << nl;
}
