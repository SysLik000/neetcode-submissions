/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        while(n--){
            node = node->next;
        }
        if (!node)
            return head->next;
        node = node->next;
        ListNode* n_node = head;
        while(node){
            n_node = n_node->next;
            node = node->next;
        }
        n_node->next = n_node->next->next;
        return head;
    }
};
