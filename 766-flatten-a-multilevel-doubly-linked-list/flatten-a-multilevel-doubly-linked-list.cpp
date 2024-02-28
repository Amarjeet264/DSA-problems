class Solution {
    
    Node* flat(Node* head){
        Node* x=head;
        if(head->next==nullptr&&!head->child){
            return head;
        }
        if(head->child!=nullptr){
            Node* nxt=head->next;
            if(head->next==nullptr)
            {
                head->next=head->child;
                head->child->prev=head;
                head->child=nullptr;
                return flat(head->next);
            }else
            {
                head->next=head->child;
                head->child->prev=head;
                head->child=nullptr;
                Node* last=flat(head->next);
                last->next=nxt;
                if(nxt)nxt->prev=last;
                return flat(nxt);
                
            }
        }
        return flat(head->next);
    }
public:
    Node* flatten(Node* head) {
        if(head==nullptr) return head;
        flat(head);

        return head;
    }
};