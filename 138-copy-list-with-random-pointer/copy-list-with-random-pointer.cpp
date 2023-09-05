/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head;
        if(!head)return NULL;
        while(curr){
            Node* nxt=curr->next;
            Node* naya=new Node(curr->val);
            curr->next=naya;
            naya->next=nxt;
            curr=nxt;
        }
        curr=head;
        while(curr){
            if(curr->random!=NULL){
                curr->next->random=curr->random->next;
            }
            else{
                curr->next->random=NULL;
            }
            curr=curr->next->next;
        }
        Node* temp = head->next,*original=head,*copy=head->next;
        while(copy && original)
        {
            original->next = original->next?original->next->next:original->next;
            copy->next = copy->next?copy->next->next:copy->next;
            original = original->next;
            copy = copy->next;

        }
        return temp;
    }
};