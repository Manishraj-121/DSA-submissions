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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* ans=dummy;
        int carry=0;
        int x;

        while(t1 != nullptr || t2 != nullptr){
            if(t1!=nullptr && t2!=nullptr){
                 x = t1->val + t2->val + carry;
            }
            else if(t1==nullptr && t2!=nullptr){
                 x =t2->val + carry;
            }
            else if(t1!=nullptr && t2==nullptr){
                 x = t1->val + carry;
            }
            carry=x/10;
            ans->next = new ListNode(x % 10);
            if(t1)t1=t1->next;
            if(t2)t2=t2->next;
            ans=ans->next;
        }
        if(carry!=0){
            ans->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
