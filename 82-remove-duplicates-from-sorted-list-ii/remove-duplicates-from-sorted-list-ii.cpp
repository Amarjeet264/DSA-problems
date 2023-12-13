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
        ListNode* newhead=NULL;
        ListNode* curr=head;
        ListNode* h=nullptr;
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
                    h=naya;
                    newhead=naya;
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
                newhead = curr;
            }
            else{
                h -> next = curr;
            }
        }
        return newhead;
    }
};