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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd=new ListNode(-1);
        ListNode* even=new ListNode(-1);
        ListNode* dummy=odd;
        ListNode* dummy1=even;
        ListNode* curr=head;
        int cnt=1;
        while(curr!=NULL){
            if(cnt%2!=0){
                odd->next=new ListNode(curr->val);
                odd=odd->next;
            }
            else{
                even->next=new ListNode(curr->val);
                even=even->next;
            }
            curr=curr->next;
            cnt++;
        }
        odd->next=dummy1->next;
        even->next=nullptr;
        // if(head->val%2!=0){
        //     even->next=NULL;
        //     odd->next=dummy1->next;
        //     return dummy->next;
        // }
        // odd->next=NULL;
        // even->next=dummy->next;
        return dummy->next;
    }
};