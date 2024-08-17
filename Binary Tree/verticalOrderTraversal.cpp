// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include<map>
#include<queue>
using namespace std ;
class Node{
    public:
    int data ;
    Node * left ;
    Node * right ;
    Node(int data){
        this -> data = data ;
        left = NULL ;
        right = NULL ;
    }
};
vector<int> printVerticalOrder(Node * root){
    vector<int> ans ;

    if(root == NULL) return ans ;
    map<int,vector<int>> mp ;

    queue< pair<Node * , int> > q;

    q.push({root,0}) ;
    while(q.size()){
        pair<Node*,int> top = q.front() ;
        q.pop() ;
        Node * node = top.first ;
        int level = top.second ;
        mp[level].push_back(node -> data);

        if(node -> left){
            q.push({node->left,level-1}) ;
        }
        if(node -> right){
            q.push({node -> right , level + 1}) ;
        }
    }

    for(auto it : mp){
        for(auto elem : it.second){
            ans.push_back(elem) ;
        }
    }
    return ans ;
}
int main() {
    // Construct the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */

    vector<int> result = printVerticalOrder(root);

    cout << "Vertical Order Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}