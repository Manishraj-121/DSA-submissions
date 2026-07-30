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
        ListNode* temp=head;
        int count=0;
        if(head==nullptr)return nullptr;
        if(head->next == nullptr && n==1)return nullptr;
    
        while(count!=n){
            count++;
            temp=temp->next;
        }
          // Delete the head node
        if (temp == nullptr)
            return head->next;

        ListNode* temp1 = head;

       
        while(temp->next!=nullptr){
            temp=temp->next;
            temp1=temp1->next;
        }
        temp1->next=temp1->next->next;
        return head;
    }
};
