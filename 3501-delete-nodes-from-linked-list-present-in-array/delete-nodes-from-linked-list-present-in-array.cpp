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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        ListNode* dum = new ListNode(-1);
        dum->next = head;
        ListNode* temp = dum;
        while(temp->next){
            if(st.find(temp->next->val)!=st.end()){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        return dum->next;
    }
};