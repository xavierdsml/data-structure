/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    void makeParent(Node* root, unordered_map<Node*, Node*>& mParent){
        queue<Node*>qt;
        qt.push(root);
        
        while(!qt.empty()){
            Node* node = qt.front();
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
    
    Node* findNode(Node* root, int val) {
        if (!root) return NULL;
        if (root->data == val) return root;

        Node* left = findNode(root->left, val);
        if (left) return left;

        return findNode(root->right, val);
    }
    
public:
    int minTime(Node* root, int targetVal) {
        unordered_map<Node*, Node*> mParent;
        makeParent(root, mParent);
        
        Node* target = findNode(root, targetVal);
        if(!target) return 0;
        
        unordered_map<Node*, bool> vis;
        queue<Node*> qt;
        
        qt.push(target);
        vis[target] = true;
        
        int minTime = 0;
        
        while(!qt.empty()){
            int size = qt.size();
            int flg = 0;
            
            for(int i = 0; i<size; i++){
                Node* node = qt.front();
                qt.pop();
                
                if(node->left && !vis[node->left]){
                    flg = 1;
                    qt.push(node->left);
                    vis[node->left] = true;
                }
                
                if(node->right && !vis[node->right]){
                    flg = 1;
                    qt.push(node->right);
                    vis[node->right] = true;
                }
                
                if(mParent.find(node) != mParent.end() && !vis[mParent[node]]){
                    flg = 1;
                    qt.push(mParent[node]);
                    vis[mParent[node]]= true;
                }
            }
            if(flg) minTime++;
        }
        return minTime;
    }
};
