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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>qt;
        bool leftToRight = true;
        if(root==nullptr) return ans;
        qt.push(root);
        while(!qt.empty()){
            int size = qt.size();
            vector<int>level(size);
            for(int i=0; i<size; i++){
                TreeNode* node = qt.front();
                qt.pop();

                int ind = (leftToRight) ? i : (size-1-i);
                level[ind] = node->val;
                if(node->left != nullptr) qt.push(node->left);
                if(node->right != nullptr) qt.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        return ans;
    }
};
