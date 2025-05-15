#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<TreeNode*> generateTrees(int n) {
            vector<vector<TreeNode*>> dp(n + 1, vector<TreeNode*>());
            dp[0].push_back(nullptr);
            dp[1].push_back(new TreeNode(1));
    
            for(int i = 2; i <= n; i++){
                // parent
                for(int j = 1; j <= i; j++){
                    // trees in left and right
                    for(TreeNode* left : dp[j - 1]){
                        for(TreeNode* right: dp[i - j]){
                            TreeNode* root = new TreeNode(j);
                            root->left = buildTree(left, 0);
                            root->right = buildTree(right, j);
                            dp[i].push_back(root);
                        }
                    }
                }
            }
    
            return dp[n];
        }
    
        TreeNode* buildTree(TreeNode* root, int s){
            if(root == nullptr) return nullptr;
    
            TreeNode* newNode = new TreeNode(root->val + s);
            newNode->left = buildTree(root->left, s);
            newNode->right = buildTree(root->right, s);
            return newNode;
        }
};