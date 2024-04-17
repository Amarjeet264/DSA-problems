class MyCircularDeque {
    deque<int>dq;
    int x=0;
public:
    MyCircularDeque(int k) {
        x=k;
    }
    
    bool insertFront(int value) {
        if(dq.size()<x){
            dq.push_front(value);
            return true;
        }
        return 0;
    }
    
    bool insertLast(int value) {
        if(dq.size()<x){
            dq.push_back(value);
            return true;
        }
        return 0;
    }
    
    bool deleteFront() {
        if(dq.size()>0){
            dq.pop_front();
            return true;
        }
        return 0;
    }
    
    bool deleteLast() {
        if(dq.size()>0){
            dq.pop_back();
            return true;
        }
        return 0;
    }
    
    int getFront() {
        if(dq.size()>0){
            return dq.front();
        }
        return -1;
    }
    
    int getRear() {
        if(dq.size()>0){
            return dq.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        if(dq.size()==0){
            return 1;
        }
        return 0;
    }
    
    bool isFull() {
        if(dq.size()==x){
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */