#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

void preorder(Node* root){
    if(root==nullptr){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);

    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    root->right->left->left = new Node(7);

    cout<<"Pre-Order Traversal: "<<endl;
    preorder(root);
    cout<<"\nIn-Order Traversal: "<<endl;
    inorder(root);
    cout<<"\nPost-Order Traversal: "<<endl;
    postorder(root);

}
