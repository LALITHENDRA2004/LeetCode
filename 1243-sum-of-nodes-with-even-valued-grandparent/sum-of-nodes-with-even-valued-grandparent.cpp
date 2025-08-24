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
    int addChilds(TreeNode *node) {
        if(node == NULL) return 0;
        int sum = 0;
        if(node -> left) sum += node -> left -> val;
        if(node -> right) sum += node -> right -> val;
        return sum;
    }
    void findSum(TreeNode* root, int& sum) {
        if(root == NULL) return;
        if(root -> val % 2 == 0) {
            sum += addChilds(root -> left);
            sum += addChilds(root -> right);
        } 
        findSum(root -> left, sum);
        findSum(root -> right, sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        findSum(root, sum);
        return sum;
    }
}; 