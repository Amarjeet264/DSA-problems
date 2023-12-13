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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* h=dummy;
        ListNode* curr=head;
        // ListNode* h=nullptr;
        if(!head||!head->next)return head;
        bool f=false;
        while(curr&&curr->next){
            if(curr->val==curr->next->val){
                while(curr->next&&curr->val==curr->next->val){
                    curr=curr->next;

                }
                if(curr->next==nullptr){
                    f=true;
                    break;
                }
            }
            else{
                if(h==nullptr){
                    ListNode* naya=new ListNode(curr->val);
                    naya->next=nullptr;
                    h->next=naya;
                    h=h->next;
                }
                else{
                    ListNode* naya=new ListNode(curr->val);
                    naya->next=nullptr;
                    h->next=naya;
                    h=h->next;
                }
            }
            curr=curr->next;
        }
        if(f==false){
            if(h == NULL) {
                h->next = curr;
            }
            else{
                h -> next = curr;
            }
        }
        return dummy->next;
    }
};