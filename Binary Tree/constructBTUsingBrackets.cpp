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



// second solution


class Solution{
public:
    Node* buildTree(string str, int& index){
        if(index >= str.length()) return NULL;
        // if a closing bracket appears before a digit, that means its a null value and hence we handle it acoordingly
        if(str[index] == ')'){
            index++;
            return NULL;
        }
        
        // Handling Multiple integers
        int data = 0;
        while(str[index] != '(' && str[index] != ')'){
            data = data*10 + str[index]-'0';
            index++;
            if(index >= str.length()) break;
        }
        
        Node* root = new Node(data);
        
        // if another opening bracket is there we either input left or right node
        if(str[index] == '(') root->left = buildTree(str, ++index);
        if(str[index] == '(') root->right = buildTree(str, ++index);
        
        // if closing bracket appears we increase the index and move onto next element
        if(str[index] == ')') index++;
        return root;
    }

    
    Node *treeFromString(string str){
        int index = 0;
        return buildTree(str, index);
    }
};


