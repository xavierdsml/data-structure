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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    
    vector<int> topView(Node *root) {
        vector<int>ans;
        queue<pair<Node*,int>> qt;
        map<int,int> mpp;
        if(root == nullptr) return ans;
        qt.push({root,0});
        while(!qt.empty()){
            
            auto p = qt.front();
            qt.pop();
            
            Node* node = p.first;
            int line = p.second;
            
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data;
            if(node->left != nullptr) qt.push({node->left,line-1});
            if(node->right != nullptr) qt.push({node->right,line+1});
        }
        for(auto p: mpp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
