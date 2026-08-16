/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<string> v;
    void recursion(TreeNode* root, string s) {
        if(s!="") s+="->";
        s += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            v.push_back(s);
            return;
        }

        if (root->left) {
            recursion(root->left, s);
        }
        if (root->right) {
            recursion(root->right, s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        recursion(root, "");
        return v;
    }
};