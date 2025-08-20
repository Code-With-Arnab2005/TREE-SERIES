#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value) {
        val = value;
        left = right = nullptr;
    }
};

vector<int> preorder_iterative(Node* root){
    vector<int> ans;
    stack<Node*> st;
    if(root) st.push(root);
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
        ans.push_back(node->val);
    }
    return ans;
}


int main(){
    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);

    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    root->right->left->left = new Node(7);

    cout<<"Level-Order(DFS) Traversal: "<<endl;
    vector<int> ans = preorder_iterative(root);
    for(int &it: ans){
        cout<<it<<" ";
    }
}
