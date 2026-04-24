// Insights
// Extreme left child is the root
// do inorder traversal
// make the first node as root and build tree;
class Solution {
public:
    // writing inorder traversal for the nth timeee!
    vector<int> v;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        int n = v.size();
        // i have the sorted nodes in v
        // make the v[0] as root;
        TreeNode* new_root = new TreeNode(v[0]);
        TreeNode* tail = new_root;
        for(int i = 1; i < n ; i++){
            TreeNode* curr = new TreeNode(v[i]);
            tail->right=curr;
            tail = tail->right;
        }
        return new_root;

    }
};