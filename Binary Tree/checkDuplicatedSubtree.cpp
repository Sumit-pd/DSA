class Solution {
    int checkStatus(Node* root) {
        if (root == NULL) {
            return 0;  // Node does not exist
        }
        else if (root->left == NULL && root->right == NULL) {
            return 1;  // Leaf node
        }
        else {
            return 2;  // Internal node
        }
    }

    bool helper(Node* root, unordered_set<string>& st) {
        if (root == NULL) {
            return false;
        }

        int leftStatus = checkStatus(root->left);
        int rightStatus = checkStatus(root->right);

        // Handle cases with one child or two children
        if (leftStatus == 0 && rightStatus == 0) {
            // Leaf node, nothing to process
            return false;
        } 
        else if (leftStatus == 1 && rightStatus == 0) {
            // The node has one left child
            string str = "";
            str += root->data;
            str += root->left->data;
            str += "$";

            if (st.find(str) != st.end()) {
                return true;  // Duplicate subtree found
            }
            st.insert(str);
        } 
        else if (leftStatus == 0 && rightStatus == 1) {
            // The node has one right child
            string str = "";
            str += root->data;
            str += "$";
            str += root->right->data;

            if (st.find(str) != st.end()) {
                return true;  // Duplicate subtree found
            }
            st.insert(str);
        } 
        else if (leftStatus == 1 && rightStatus == 1) {
            // The node has two children
            string str = "";
            str += root->data;
            str += root->left->data;
            str += root->right->data;

            if (st.find(str) != st.end()) {
                return true;  // Duplicate subtree found
            }
            st.insert(str);
        } 
        else {
            // Recursive checks on non-leaf children
            if (leftStatus == 2 && helper(root->left, st)) {
                return true;  // Duplicate found in left subtree
            }
            if (rightStatus == 2 && helper(root->right, st)) {
                return true;  // Duplicate found in right subtree
            }
        }

        return false;  // No duplicate subtree found
    }

  public:
    bool dupSub(Node* root) {
        unordered_set<string> st;
        return helper(root, st);  // Call helper function to find duplicate subtrees
    }
};
