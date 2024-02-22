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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head;
        bool karo=false;
        bool change=false;
        ListNode* ans=head;
        ListNode* pichlarev=nullptr;
        while(curr){
            if(karo==false){
                prev=curr;
                curr=curr->next;
            }
            else{
                if(pichlarev){
                    pichlarev->next=curr;
                }
                ListNode* nxt=curr->next;
                curr->next=prev;
                prev->next=nxt;
                pichlarev=prev;
                if(ans==head){
                    ans=curr;
                }
                curr=nxt;
            }
            if(!curr||!prev)continue;
            // cout<<curr->val<<" "<<prev->val<<" ";
            if(pichlarev){
                cout<<pichlarev->val;
            }
            // cout<<endl;
            karo=!karo;
        }
        return ans;
    }
};