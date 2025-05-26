#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
    public:
        vector<vector<int>> kthParent;
        int maxDepth = 0;
        TreeAncestor(int n, vector<int>& parent) {
            // maximum levels are n so if we can represent n in binary form
            // to represent n in binary form we need log n depth
            while ((1 << maxDepth) <= n)
                maxDepth++;
            // initializing with -1 to cover any no parent cases
            kthParent.resize(n, vector<int>(maxDepth, -1));
    
            // i = 0 => direct parents filling
            for (int j = 0; j < n; j++) {
                kthParent[j][0] = parent[j];
            }
    
            // parent array is given so directly start building the kthParent
            // precomputation
            for (int i = 1; i < maxDepth; i++) {
                for (int j = 0; j < n; j++) {
                    // 2 ^ i parent => 2 ^ i - 1 parent of 2 ^ i - 1 parent
                    int curr = kthParent[j][i - 1];
                    if (curr != -1)
                        kthParent[j][i] = kthParent[curr][i - 1];
                }
            }
        }
    
        int getKthAncestor(int node, int k) {
            int jump = 0;
            while(k > 0 && node != -1){
                if(k & 1) node = kthParent[node][jump];
                k = k >> 1;
                jump++;
            }
            return node;
        }
};
    