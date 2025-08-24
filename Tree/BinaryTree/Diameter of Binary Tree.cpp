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
    int BinaryTree(TreeNode* root, int &maxi) {
        if(root == nullptr) return 0;

        int l = BinaryTree(root->left, maxi);
        int r = BinaryTree(root->right, maxi);

        maxi = max(maxi, l+r);
        return 1 + max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        BinaryTree(root, maxi);
        return maxi;
    }
};
