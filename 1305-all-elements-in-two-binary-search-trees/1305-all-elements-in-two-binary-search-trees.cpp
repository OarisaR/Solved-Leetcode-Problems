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
    vector<int> v1, v2;
    void inorder(TreeNode* root, vector<int>& v) {
        if (root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    vector<int> merge(vector<int>& v1, vector<int>& v2) {
        vector<int> ans;
        int i = 0, j = 0;
        // 1 2 4 , 0 1 3
        while (i < v1.size() && j < v2.size()) {

            if (v1[i] <= v2[j]) {
                ans.push_back(v1[i]);
                i++;
            } else {
                ans.push_back(v2[j]);
                j++;
            }
        }
        while (i < v1.size()) {
            ans.push_back(v1[i]);
            i++;
        }

        while (j < v2.size()) {
            ans.push_back(v2[j]);
            j++;
        }

        return ans;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1, v1);
        inorder(root2, v2);
        // now merge v1,v2 in sorted order;
        vector<int> ans = merge(v1, v2);
        return ans;
    }
};