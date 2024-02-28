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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr=head->next;
        // ListNode* dummy=new ListNode(-1);
        // dummy->next=curr;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr1=dummy;
        int sum=0;
        while(curr){
            // cout<<curr->val<<" ";
            sum+=curr->val;
            if(curr->val==0){
                curr1->next=new ListNode(sum);
                curr1=curr1->next;
                sum=0;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};