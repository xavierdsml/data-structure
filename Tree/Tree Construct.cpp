#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;;
    TreeNode* right;
    
    
    TreeNode(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
    
    TreeNode(int data, TreeNode* leftchild, TreeNode* rightchild){
        val = data;
        left = leftchild;
        right = rightchild;
    }
};


int main(){
    struct TreeNode* leftchild = new TreeNode(6);
    struct TreeNode* rightchild = new TreeNode(7);
    
    struct TreeNode*root = new TreeNode(5, leftchild, rightchild);
    
    cout<< root->val<<endl;
    
    cout<<root->left->val<<" ";
    cout<<root->right->val<<endl;
    
    return 0;
}