#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = right = nullptr;
    }
    
    Node(int val, Node* leftNode, Node* rightNode){
        data = val;
        left = leftNode;
        right = rightNode;
    }
};


int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    
    root->left->right = new Node(5);
    
    cout<< root->data <<endl;
    cout<< root->left->data <<endl;
    cout<< root->right->data <<endl;
    cout<< root->left->right->data <<endl;
}
