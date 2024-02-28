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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int prev=-1;
        int justprev=-1;
        int firstprev=-1;
        ListNode* curr=head;
        int cnt=0;
        while(curr){
            if(prev!=-1&&curr->next&&curr->val>prev&&(curr->next->val<curr->val)){
                cout<<curr->val<<" "<<firstprev<<" "<<justprev<<endl;
                if(firstprev==-1){
                    firstprev=cnt;
                    justprev=cnt;
                }
                else{
                    maxi=cnt-firstprev;
                    mini=min(mini,cnt-justprev);
                    justprev=cnt;
                }
                // cout<<curr->val<<" "<<firstprev<<" "<<justprev<<endl;
            }
            else if(prev!=-1&&curr->next&&curr->val<prev&&(curr->next->val>curr->val)){
                if(firstprev==-1){
                    firstprev=cnt;
                    justprev=cnt;
                }
                else{
                    maxi=cnt-firstprev;
                    mini=min(mini,cnt-justprev);
                    justprev=cnt;
                }
            }
            prev=curr->val;
            cnt++;
            curr=curr->next;
        }
        if(mini==INT_MAX){
            return {-1,-1};
        }
        return {mini,maxi};
    }
};