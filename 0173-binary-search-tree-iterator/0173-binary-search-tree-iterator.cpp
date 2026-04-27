class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        // constructor

        // pushing all small nodes to the stack
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

    int next() {
        auto top = st.top();
        st.pop();
        if (top->right) {
            TreeNode* node = top->right; // start from right child
            while (node != NULL) {
                st.push(node);
                node = node->left ;
            }
        }
        return top->val;
    }

    bool hasNext() {
        if (st.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */