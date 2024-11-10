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
    ListNode* ans = nullptr;
    ListNode* rev(ListNode* head){
        if(!head||!head->next){
            return head;
        }
        ListNode *temp = head;
        ListNode* naya = rev(head->next);
        temp->next = nullptr;
        if(ans==nullptr)ans = naya;
        naya->next = temp;
        return temp;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)return head;
        rev(head);
        return ans;
    }
};