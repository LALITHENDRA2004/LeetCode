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
    int Depth(TreeNode *root) {
        if(root == NULL) return 0;
        int left = Depth(root -> left);
        int right = Depth(root -> right);
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool l = true, r = true;
        if(root != NULL) {
            int left = Depth(root -> left);
            int right = Depth(root -> right);
            if(abs(left - right) > 1) return false;
            l = isBalanced(root -> left);
            r = isBalanced(root -> right);
        }
        return l && r;
        
        
    }
};