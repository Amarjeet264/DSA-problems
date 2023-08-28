class MyStack {
public:
queue<int> q1;
queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        while(q.size()>1){
            q1.push(q.front());
            q.pop();
        }
        int x=q.front();
        q.pop();
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
        }
        return x;
    }
    
    int top() {
        while(q.size()>1){
            q1.push(q.front());
            q.pop();
        }
        int x=q.front();
        q1.push(x);
        q.pop();
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
        }
        return x;
    }
    
    bool empty() {
        if(q.size()==0){
            return 1;
        }
        else{
            return 0;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */