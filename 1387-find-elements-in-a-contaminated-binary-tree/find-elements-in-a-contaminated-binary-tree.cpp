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
class FindElements {
    private:
        map<int, bool> contains;
        void change(TreeNode *root, int val) {
            if(root == NULL) return;
            
            root -> val = val;
            contains[root -> val] = true;
            change(root -> left, val * 2 + 1);
            change(root -> right, val * 2 + 2);
        }
public:
    FindElements(TreeNode* root) {
        if(root == NULL) return;
        change(root, 0);
    }
    
    bool find(int target) {
        return contains[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */