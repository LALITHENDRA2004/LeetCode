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
    void traverse(TreeNode* root, map<int, int> &mp, int &mode) {
        if(root == NULL) return;
        mp[root -> val]++;
        mode = max(mode, mp[root -> val]);
        traverse(root -> left, mp, mode);
        traverse(root -> right, mp, mode);
    }
    vector<int> findMode(TreeNode* root) {
        map<int, int> cnt;
        vector<int> ans;
        int mode = INT_MIN;
        traverse(root, cnt, mode);
        for(auto i : cnt) {
            if(i.second == mode) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};