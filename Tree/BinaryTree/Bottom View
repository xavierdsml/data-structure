/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        
        queue<pair<Node*, int>> qt;
        map<int,int>mpp;
        vector<int>ans;
        if(root == nullptr) return ans;
        
        qt.push({root,0});
        while(!qt.empty()){
            auto p = qt.front();
            qt.pop();
            
            Node* node = p.first;
            int level = p.second;
            mpp[level] = node->data;
            
            if(node->left != nullptr) qt.push({node->left,level-1});
            if(node->right != nullptr) qt.push({node->right,level+1});
        }
        
        for(auto p: mpp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
