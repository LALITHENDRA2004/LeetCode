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
    TreeNode* build(vector<int> &nums, int start, int end) {
        if(start > end) return NULL;
        if(start == end) {
            return new TreeNode(nums[start]);
        }
        int mid = start + (end - start + 1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* leftNode = build(nums, start, mid - 1);
        TreeNode* rightNode = build(nums, mid + 1, end);
        root -> left = leftNode;
        root -> right = rightNode;
        return root; 
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = build(nums, 0, nums.size() - 1);
        return root;
    }
};