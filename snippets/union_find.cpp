#include <bits/stdc++.h>
using namespace std;

class UF{
    private: 
        int n;
        vector<int> size;
        vector<int> parent;
        vector<int> rank;
    public:
        UF(int n): n(n), parent(n), rank(n, 0), size(n, 1) {
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        // union by size
        void union_sets_size(int u, int v){
            int a = find_set(u);
            int b = find_set(v);
            
            if(a != b){
                if(size[a] < size[b]) swap(a, b);
                // small to big
                parent[b] = a;
                size[a] += size[b];
            }
        }

        // union by rank
        void union_sets_rank(int u, int v){
            int a = find_set(u);
            int b = find_set(v);

            if(a != b){
                if(rank[a] < rank[b]) swap(a, b);
                // low rank to high rank
                parent[b] = a;

                if(rank[a] == rank[b]) rank[a]++;
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