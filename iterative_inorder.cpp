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

vector<int> inorder_iterative(Node* root){
    vector<int> ans;
    stack<Node*> st;
    Node* node = root;
    while(1){
        if(node){
            st.push(node);
            node = node->left;
        } else {
            if(st.empty()) break;
            Node* top = st.top();
            st.pop();
            ans.push_back(top->val);
            node = top->right;
        }
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
    vector<int> ans = inorder_iterative(root);
    for(int &it: ans){
        cout<<it<<" ";
    }
}
