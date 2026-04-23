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
    
    vector<TreeNode*> generate(int start, int end) {
        if (start > end)
            return {NULL};
        vector<TreeNode*> trees;
        for (int j = start; j <= end; j++) {
            // taking j as root
            auto lefts = generate(start, j - 1); // build left subtree
            auto rights = generate(j + 1, end);  // build right subtree
            // merge
            for (auto l : lefts) {
                for (auto r : rights) {
                    TreeNode* node = new TreeNode(j); // j is the value of root
                    node->left = l;
                    node->right = r;
                    trees.push_back(node);
                }
            }
        }
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) { return generate(1, n); }
};