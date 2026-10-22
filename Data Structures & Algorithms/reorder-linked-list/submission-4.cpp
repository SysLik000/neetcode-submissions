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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reverse = slow->next;
        slow->next = nullptr;

        ListNode* previous = nullptr;
        while (reverse){
           auto next = reverse->next;
           reverse->next = previous;
           previous = reverse;
           reverse = next;
        }
        reverse = previous;

        ListNode* target = head;
        while (reverse){
            auto nextTarget = target->next;
            auto nextReverse = reverse->next;

            target->next = reverse;
            reverse->next = nextTarget;

            target = nextTarget;
            reverse = nextReverse;
        }
    }
};
