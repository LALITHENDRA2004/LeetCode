/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node -> next -> next!= NULL) {
            swap(node -> val, node -> next -> val);
            node = node -> next;
        }
        swap(node -> val, node -> next -> val);
        node -> next = NULL;
    }
};