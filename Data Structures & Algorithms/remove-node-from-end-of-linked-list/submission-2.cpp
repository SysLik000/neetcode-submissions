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



// TODO: slow and fast iterators
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* right = head;
        while(n--){
            right = right->next;
        }
        ListNode head_holder(0, head);
        ListNode *left = &head_holder;
        while(right){
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return head_holder.next;
    }
};
