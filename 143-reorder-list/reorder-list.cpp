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
    void reorderList(ListNode* head) {
        vector<int>v;
        ListNode* curr=head;
        while(curr!=NULL){
            v.push_back(curr->val);
            curr=curr->next;
        }
        // ListNode* dummy=new ListNode(-1);
        ListNode* temp=head;
        // if(head==NULL||head->next==NULL){
        //     return head;
        // }
        int i=1;
        int j=v.size()-1;
        head=temp;
        if(head!=NULL&&head->next!=NULL){
        while(i<j){
            // cout<<v[i]<<" ";
            if(i<j){
            temp->next=new ListNode(v[j]);
               j--;
               temp=temp->next;
            }
            // temp->next=new ListNode(v[i]);
            // temp=temp->next;
            // i++;
            if(i<j){
                 temp->next=new ListNode(v[i]);
            temp=temp->next;
            i++;
            //    temp->next=new ListNode(v[j]);
            //    j--;
            //    temp=temp->next;
            }
        }
        temp->next=new ListNode(v[v.size()/2]);
        temp=temp->next;
        }
    }
};