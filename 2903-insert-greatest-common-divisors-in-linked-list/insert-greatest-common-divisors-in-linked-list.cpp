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
    int gcd(int a, int b)
{
    int result = ((a < b) ? a : b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
 
    return result;
}
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head){
            return NULL;
        }
        ListNode* curr=head->next;
        ListNode* prev=head;
        ListNode* nxt=NULL;
        while(curr){
            ListNode* naya=new ListNode(gcd(prev->val,curr->val));
            prev->next=naya;
            naya->next=curr;
            prev=curr;
            curr=curr->next;
        }
        if(curr==NULL){
            prev->next=new ListNode(prev->val);
        }
        prev->next=NULL;
        return head;
    }
};