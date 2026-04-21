class Solution {
public:
    vector<int> v;

    //building the sorted array from the given nodes
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    // building the tree from the sorted array
    TreeNode* buildBST(int left, int right) {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2; // root is always in the mid of inorder traversal
        TreeNode* root = new TreeNode(v[mid]);
        root->left = buildBST(left, mid - 1);
        root->right = buildBST(mid + 1, right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return buildBST(0, v.size()-1);
    }
};