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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* agla=nullptr;
        ListNode* curr=list1;
        while(a!=1){
            curr=curr->next;
            a--;
            b--;
        }
        ListNode* x=curr;
        while(x&&b>=0){
            x=x->next;
            b--;
        }
        cout<<x->val<<" ";
        curr->next=list2;
        ListNode* y=list2;
        while(y->next){
            y=y->next;
        }
        y->next=x;
        cout<<curr->val<<" ";
        return list1;
    }
};