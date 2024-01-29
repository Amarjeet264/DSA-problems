class MyQueue {
stack<int> q1;
stack<int> q;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
       q.push(x); 
    }
    
    int pop() {
       while(q.size()>1){
           q1.push(q.top());
           q.pop();
       } 
       int x=q.top();
       q.pop();
       while(!q1.empty()){
           q.push(q1.top());
           q1.pop();
       }
       return x;
    }
    
    int peek() {
         while(q.size()>1){
           q1.push(q.top());
           q.pop();
       } 
       int x=q.top();
       q1.push(x);
       q.pop();
       while(!q1.empty()){
           q.push(q1.top());
           q1.pop();
       }
       return x;
    }
    
    bool empty() {
        if(q.size()==0){
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */