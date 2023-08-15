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
    ListNode* partition(ListNode* head, int x) {
        ListNode* chota=new ListNode(-1);
        ListNode* curr1=chota;
        ListNode* bade=new ListNode(-1);
        ListNode* curr2=bade;
        ListNode* curr=head;
        while(curr){
            if(curr->val<x){
                curr1->next=curr;
                curr1=curr1->next;
            }
            else{
                curr2->next=curr;
                curr2=curr2->next;
            }
            curr=curr->next;
        }
        curr2->next=NULL;
        curr1->next=bade->next;
        return chota->next;
    }

};