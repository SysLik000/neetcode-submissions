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
        // find length
        ListNode* node = head;
        size_t length = 0;
        while (node){
            ++length;
            node = node->next;
        }
        if (length < 2)
            return;
        // find mid point
        // 'node' is a previous node
        ListNode* mid = head;
        length /= 2;
        while (length--){
            node = mid;
            mid = mid->next;
        }
        node->next = nullptr;
        // head - first half of list
        // mid - second half of list

        // reverse the second half
        // 'node' is a next node of the second half
        node = nullptr;
        while (mid){
           auto tmp = mid->next;
           mid->next = node;
           node = mid;
           mid = tmp;
        }
        mid = node;

        // merge 2 halfs into one
        // 'node' is a next of the head node
        while (head && mid){
            node = head->next;
            auto next = mid->next;

            head->next = mid;
            if (node)
                mid->next = node;
            head = node;
            mid = next;
        }
    }
};
