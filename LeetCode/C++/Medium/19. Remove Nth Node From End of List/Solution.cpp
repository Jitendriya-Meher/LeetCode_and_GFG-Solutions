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
        ListNode* slow=head;
        ListNode* fast=head;
        int i=0;
        while(fast!=NULL && i<n)
        {
            i++;
            fast=fast->next;
        }
        if(fast!=NULL)
        {
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        }
        if(slow==head && fast==NULL)
        {
            head=head->next;
            return head;
        }
        else
        {
            slow->next=slow->next->next;
            return head;
        }
    }
    
};