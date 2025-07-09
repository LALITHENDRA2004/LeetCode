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
    int rightMost(TreeNode* node) {
        if(node == NULL) return INT_MAX;
        int last = node -> val;
        while(node) {
            if(node -> right) {
                last = node -> right -> val;
                node = node -> right;
            }
            else break; 
        }
        return last;
    }

    int leftMost(TreeNode* node) {
        if(node == NULL) return INT_MAX;
        int last = node -> val;
        while(node) {
            if(node -> left) {
                last = node -> left -> val;
                node = node -> left;
            }
            else break;
        }
        return last;
    }

    void mini(TreeNode* root, int &dif) {
        if(root == NULL) return;
        int leftMin = rightMost(root -> left);
        int rightMin = leftMost(root -> right);
        dif = min(dif, min(abs(root -> val - leftMin), abs(root -> val - rightMin)));
        mini(root -> left, dif);
        mini(root -> right, dif);
    }

    int getMinimumDifference(TreeNode* root) {
        int dif = INT_MAX;
        mini(root, dif);
        return dif;
    }
};