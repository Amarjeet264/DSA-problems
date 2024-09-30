class CustomStack {
    stack<int>st;
    int size;
public:
    CustomStack(int maxsize) {
        size=maxsize;
    }
    
    void push(int x) {
        if(st.size()<size){
            st.push(x);
        }
    }
    
    int pop() {
        if(!st.empty()){
            int x=st.top();
            st.pop();
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        stack<int>h;
        while(!st.empty()){
            h.push(st.top());
            st.pop();
        }
        while(st.size()<k&&!h.empty()){
            st.push(h.top()+val);
            h.pop();
        }
        while(!h.empty()){
            st.push(h.top());
            h.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */