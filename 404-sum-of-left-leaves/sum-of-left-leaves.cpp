/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum(TreeNode*root, int child) {
        if(root == NULL) return 0;
        if((!root -> left) && (!root -> right) && child == -1) {
            return root -> val;
        }
        int left = sum(root -> left, -1);
        int right = sum(root -> right, 1);
        return left + right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = sum(root, 0);
        return ans;
    }
};