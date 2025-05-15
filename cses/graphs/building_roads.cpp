#include <bits/stdc++.h>
using namespace std;

struct FastIO{
    FastIO(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} FastIO;
using lli = long long;
constexpr char nl = '\n';

class UF{
    private: 
        int n;
        vector<int> size;
    public:
        vector<int> parent;
        UF(int n): n(n), parent(n), size(n, 1) {
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        // union by size
        void union_sets(int u, int v){
            int a = find_set(u);
            int b = find_set(v);
            
            if(a != b){
                if(size[a] < size[b]) swap(a, b);
                parent[b] = a;
                size[a] += size[b];
            }
        }
        
        // find with path compression
        int find_set(int u){
            if(u == parent[u]) return u;
            return parent[u] = find_set(parent[u]);
        }

        bool is_connected(int u, int v){
            return find_set(u) == find_set(v);
        }
};

int main() {
    int n, e, u, v;
    cin >> n >> e;
    UF uf(n + 1);
    for(int i = 0; i < e; i++){
        cin >> u >> v;
        uf.union_sets(u, v);
    }

    set<int> pts;
    for(int i = 1; i <= n; i++){
        uf.find_set(i);
        pts.insert(uf.parent[i]);
    }

    int s = pts.size();
    cout << s - 1 << nl;
    if(s > 1) {
        int prev = *pts.begin();
        auto curr = ++pts.begin();
        while(curr != pts.end()){
            cout << prev << " " << *curr << nl;
            prev = *curr;
            ++curr;
        }
    }
}


