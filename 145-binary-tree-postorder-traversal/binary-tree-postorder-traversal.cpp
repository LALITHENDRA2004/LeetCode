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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> st1, st2;
        vector<int> ans;
        st1.push(root);
        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            if(node -> left) st1.push(node -> left);
            if(node -> right) st1.push(node -> right);
            st2.push(node);
        }
        //cout << st2.size() << endl;
        while(!st2.empty()) {
            ans.push_back(st2.top() -> val);
            st2.pop();
        }
        return ans;
    }
};