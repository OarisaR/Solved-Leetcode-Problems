class Solution {
public:
   // We need to know about all nodes greater than the current node by the time we visit it
   // REVERSE INORDER TRAVERSAL  : DESCENDING ORDER
    void rev_inorder(TreeNode* root, int &sum){
        if(root==NULL) return;
        rev_inorder(root->right,sum);
        sum+=root->val;
        root->val = sum;
        rev_inorder(root->left,sum);

    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        rev_inorder(root, sum);
        return root;
    }
};