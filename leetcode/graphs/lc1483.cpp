#include <bits/stdc++.h>
using namespace std;

// refer to binary lifting in notes
class TreeAncestor {
    public:
        int row;
        vector<vector<int>> up;
        TreeAncestor(int n, vector<int>& parent) {
            this->row = log2(n) + 1;
            up.resize(n, vector<int> (this->row, -1));
    
            parent[0] = -1;
            for(int i = 0; i < n; i++){
                up[i][0] = parent[i];
            }
    
            for(int j = 1; j < row; j++){
                for(int i = 0; i < n; i++){
                    int nodep = up[i][j - 1];
                    if(nodep != -1) up[i][j] = up[nodep][j - 1];
                }
            }
        }
        
        int getKthAncestor(int node, int k) {
            for(int i = 0; i < row; i++){
                if(k & (1 << i)){
                    node = up[node][i];
                }
                if(node == -1) return -1;
            }
            return node;
        }
    };
    
    /**
     * Your TreeAncestor object will be instantiated and called as such:
     * TreeAncestor* obj = new TreeAncestor(n, parent);
     * int param_1 = obj->getKthAncestor(node,k);
     */