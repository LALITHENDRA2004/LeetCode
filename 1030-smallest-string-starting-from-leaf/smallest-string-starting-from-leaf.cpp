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
    void find(string s, string &ans, TreeNode *root) {
        if(root == NULL) {
            return;
        }
        s = (char)(97 + root -> val) + s;
        find(s, ans, root -> left);
        if(root -> left == NULL && root -> right == NULL) {
            if(ans == "") ans = s;
            else {
                if(s < ans) ans = s;
            }
            s.pop_back();
        }
        find(s, ans, root -> right);
    }
    string smallestFromLeaf(TreeNode* root) {
        string s = "", ans = "";
        find(s, ans, root);
        return ans;
    }
};