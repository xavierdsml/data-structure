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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        //if root is null then no tree
        if(root == nullptr) return ans;

        queue<TreeNode*>qt;
        qt.push(root);
        
        while(!qt.empty()){
            int size = qt.size(); //aalg se define krna hoga
            vector<int>level;
            //jithna queue mai elemnt hai uthna baar chlega loop
            for(int i=0; i<size; i++){
                TreeNode*node = qt.front();
                qt.pop();
                level.push_back(node->val);
                if(node->left!=nullptr) qt.push(node->left);
                if(node->right!=nullptr) qt.push(node->right);
                
            }
            ans.push_back(level);
        }
        return ans;
    }
};
