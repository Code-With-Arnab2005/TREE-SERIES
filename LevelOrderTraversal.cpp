#include<iostream>
#include<vector>
#include<deque>
#include<queue>
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

vector<vector<int>> level_order(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> level;
        int size = q.size();
        for(int i=0; i<size; i++){
            Node* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
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
    vector<vector<int>> ans = level_order(root);
    for(vector<int> &level: ans){
        for(int &it: level){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
