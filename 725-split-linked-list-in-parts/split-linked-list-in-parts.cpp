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
        vector<ListNode*> res(k, nullptr);
        curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* x = new ListNode(0);
            ListNode* y = x;
            for (int j = 0; j < n / k; j++) {
                y->next = curr;
                y = curr;
                curr = curr->next;
            }
            if (n % k > i) {
                y->next = curr;
                y = curr;
                curr = curr->next;
            }
            y->next = nullptr;
            res[i] = x->next;
        }
        return res;
    }
};