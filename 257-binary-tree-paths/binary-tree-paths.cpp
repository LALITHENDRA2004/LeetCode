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
    void find(string s, vector<string> &ans, TreeNode *root) {
        if(root == NULL) {
            return;
        }
        else if(root -> left == NULL && root -> right == NULL) {
            s += to_string(root -> val);
            ans.push_back(s);
            return;
        }
        find(s + to_string(root -> val) + "->", ans, root -> left);
        find(s + to_string(root -> val) + "->", ans, root -> right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        find(s, ans, root);
        return ans;
    }
};