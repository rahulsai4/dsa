#include<bits/stdc++.h>
using namespace std;

class UF {
public:
    vector<int> id;
    vector<int> rank;

    // initially for each node parent is itself and rank = 0
    UF(int n) {
        id.resize(n);
        for (int i = 0; i < n; i++) id[i] = i;
        rank.resize(n, 0);
    }

    // based on rank merge the parents
    void unite(int u, int v) {
        int uRoot = find(u);
        int vRoot = find(v);

        if (uRoot == vRoot) return;

        if (rank[uRoot] < rank[vRoot]) {
            id[uRoot] = vRoot;
        } else if (rank[uRoot] > rank[vRoot]) {
            id[vRoot] = uRoot;
        } else {
            id[vRoot] = uRoot;
            rank[uRoot]++;
        }
    }

    // recursive path compression
    int find(int u) {
        if (u == id[u])
            return u;
        return id[u] = find(id[u]);
    }

    bool isConnected(int u, int v) { return find(u) == find(v); }
};