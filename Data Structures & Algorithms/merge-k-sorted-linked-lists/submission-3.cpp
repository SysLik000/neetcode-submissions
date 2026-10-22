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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        
        while (lists.size() > 1){
            vector<ListNode*> merged_lists;
            int i = 1;
            for(; i < lists.size(); i += 2){
                ListNode* target = lists[i];
                ListNode* source = lists[i - 1];
                ListNode head_holder;
                ListNode *tail = &head_holder;
                while(source && target){
                    if (target->val <= source->val){
                        tail->next = target;
                        target = target->next;
                    } else {
                        tail->next = source;
                        source = source->next;
                    }
                    tail = tail->next;
                }
                if (target)
                    tail->next = target;
                else
                    tail->next = source;
                merged_lists.push_back(head_holder.next);
            }
            if ((lists.size() - i) == 0 ){
                merged_lists.push_back(lists.back());
            }
            lists = std::move(merged_lists);
        }
        return lists[0];
    }
};
