class Solution{
    int i = 0; // assuming i is declared elsewhere in your code
    void solve(Node* root, string str) {
        int n = str.size();
        while (i < n && isdigit(str[i])) {
            root->data *= 10;
            root->data += str[i] - '0';
            i++;
        }
        if (i < n && str[i] == '(') {
            root->left = new Node(0);
            i++;
            solve(root->left, str);
            if (root->left->data == 0) root->left = NULL;
        }
    
        if (i < n && str[i] == '(') {
            root->right = new Node(0);
            i++;
            solve(root->right, str);
            if (root->right->data == 0) root->right = NULL;
        }
    
        if (i >= n || str[i] == ')') {
            i++;
            return;
        }
    }

public:
    // function to construct tree from string
    Node *treeFromString(string str){
        Node * root = new Node(0) ;
        solve(root,str) ;
        return root ;
    }
};