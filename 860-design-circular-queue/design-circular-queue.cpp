class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=nullptr;
    }
};
class MyCircularQueue {
public:
    int max=0;
    int curr=0;
    Node* front=nullptr;
    Node* rear=nullptr;
    MyCircularQueue(int k) {
        max=k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return 0;
        }
        Node* naya=new Node(value);
        if(front==NULL){
            front=naya;
        }
        else{
            rear->next=naya;
        }
        naya->next=front;
        rear=naya;
        curr++;
        return 1;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return 0;
        }
        if(front==rear){
            front=nullptr;
            rear=nullptr;
        }
        else{
            front=front->next;
            rear->next=front;
        }
        curr--;
        return 1;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return front->data;
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return rear->data;
    }
    
    bool isEmpty() {
        return curr==0;
    }
    
    bool isFull() {
        return curr==max;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */