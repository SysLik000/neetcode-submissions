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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head, *previous, *current, *source;
        if (!list1){
            return list2;
        }
        if (!list2){
            return list1;
        }
        if (list1->val <= list2->val){
            head = previous = list1;
            current = list1->next;
            source = list2;
        } else {
            head = previous = list2;
            current = list2->next;
            source = list1;
        }
        while (source) {
            if (!current)
                break;
            if (source->val < current->val){
                auto next = source->next; 
                source->next = current;
                previous->next = source;
                previous = source;
                source = next;
            } else {
                previous = current;
                current = current->next;
            }
        }
        if (source)
            previous->next = source;
        return head;
    }
};
