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
        int n = lists.size();
        ListNode* temp1;
        ListNode* temp2;
        ListNode* merged=lists[0];
        if(n==0)return nullptr;

        for (int i = 1; i < n; i++) {
             ListNode* dummy = new ListNode(-1);
             ListNode* ans = dummy;
            temp1 = merged;
            temp2 = lists[i];

            while (temp1 != nullptr && temp2 != nullptr) {
                if (temp1->val <= temp2->val) {
                    ans->next = temp1;
                    temp1 = temp1->next;
                } else {
                    ans->next = temp2;
                    temp2 = temp2->next;
                }
                ans = ans->next;
            }
            ans->next = (temp1 != nullptr) ? temp1 : temp2;
            merged=dummy->next;
        }
        return merged;
    }
};
