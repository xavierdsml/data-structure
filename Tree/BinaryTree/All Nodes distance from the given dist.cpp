/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mParent){
        queue<TreeNode*>qt;
        qt.push(root);
        while(!qt.empty()){
            TreeNode* node = qt.front();
            qt.pop();

            if(node->left){
                mParent[node->left] = node;
                qt.push(node->left);
            }
            if(node->right){
                mParent[node->right] = node;
                qt.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mParent;
        makeParent(root, mParent);

        queue<TreeNode*>qt;
        unordered_map<TreeNode*, bool> vis;

        qt.push(target);
        vis[target] = true;
        int dis = 0;

        while(!qt.empty()){
            int size = qt.size();
            if(dis++ == k) break;

            for(int i = 0; i<size; i++){
                TreeNode* node = qt.front();
                qt.pop();

                if(node->left && !vis[node->left]){
                    qt.push(node->left);
                    vis[node->left] = true;
                }

                if(node->right && !vis[node->right]){
                    qt.push(node->right);
                    vis[node->right] = true;
                }

                if(mParent[node] && !vis[mParent[node]]){
                    qt.push(mParent[node]);
                    vis[mParent[node]] = true;
                }
            }
        }

        vector<int> result;
        while(!qt.empty()){
            TreeNode* node = qt.front();
            qt.pop();
            
            result.push_back(node->val);
        }
        return result;
    }
};
