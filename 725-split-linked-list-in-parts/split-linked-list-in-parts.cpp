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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            n++;
            curr = curr->next;
        }
        vector<ListNode*> res;
        curr = head;
        int harek = n/k;
        int rem = n%k;
        while(curr){
            ListNode* dummy = new ListNode(-1);
            ListNode* temp = dummy;
            int cnt = 0;
            int aage = 0;
            if(rem!=0){
                aage = 1;
            }
            while(curr&&cnt<(harek+aage)){
                temp->next = new ListNode(curr->val);
                curr= curr->next;
                temp = temp->next;
                cnt++;
            }
            res.push_back(dummy->next);
            if(rem){
                rem-=1;
            }
        }
        while(res.size()<k){
            res.push_back(nullptr);
        }
        return res;
    }
};