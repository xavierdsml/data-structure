/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int Balanced(TreeNode* root) {
        if(root == nullptr) return 0;

        int l = Balanced(root->left);
        if(l < 0) return -1;

        int r = Balanced(root->right);
        if(r < 0) return -1;

        if(abs(l-r)>1) return -1;
        return 1 + max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(Balanced(root) < 0) return false;
        else return true;
    }
};
