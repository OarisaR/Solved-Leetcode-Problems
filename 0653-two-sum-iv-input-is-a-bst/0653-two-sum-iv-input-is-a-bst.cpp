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
    vector<int> v;
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
         inorder(root); 
         // v is sorted;
         // 2 3 4 5 6 7
         // 
         int l  = 0 , r = v.size() - 1;
         while(l < r){
            int curr = k  - v[l];
            if(curr == v[r]){
                return true;
            }
            else if(curr < v[r]){
                r--;
            }
            else l++;
         }
         return false;      
    }
};