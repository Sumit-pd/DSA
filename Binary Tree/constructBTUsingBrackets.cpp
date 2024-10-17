class Solution {
    int i = 0;

    void solve(Node* root, string str) {
        int n = str.size();

        // Parse the current node's data
        while (i < n && isdigit(str[i])) {
            root->data *= 10;
            root->data += str[i] - '0';
            i++;
        }

        // Check for the left child
        if (i < n && str[i] == '(') {
            i++;
            if (str[i] == ')') {  // Empty brackets, no left child
                root->left = NULL;
                i++; // Skip the closing parenthesis
            } else {
                root->left = new Node(0);
                solve(root->left, str);  // Recursively build left subtree
            }
        }

        // Check for the right child
        if (i < n && str[i] == '(') {
            i++;
            if (str[i] == ')') {  // Empty brackets, no right child
                root->right = NULL;
                i++; // Skip the closing parenthesis
            } else {
                root->right = new Node(0);
                solve(root->right, str);  // Recursively build right subtree
            }
        }

        if (i < n && str[i] == ')') {
            i++;
        }
    }

public:
    Node *treeFromString(string str) {
        if (str.empty()) return NULL;
        Node *root = new Node(0);
        solve(root, str);
        return root;
    }
};
