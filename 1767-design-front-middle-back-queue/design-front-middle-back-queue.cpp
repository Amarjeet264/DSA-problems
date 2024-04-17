class FrontMiddleBackQueue {
    deque<int>dq;
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        // if(dq.size()<x){
            dq.push_front(val);
            // return true;
        // }
        // return 0;
    }
    
    void pushMiddle(int val) {
        int sz=dq.size();
        int c=sz;
        sz=ceil(sz/2.0);
        stack<int>st;
        while(sz--){
            int x=dq.back();
            dq.pop_back();
            st.push(x);
        }
        st.push(val);
        
        while(!st.empty()){
            dq.push_back(st.top());
            st.pop();
        }
    }
    
    void pushBack(int val) {
        // if(dq.size()<x){
            dq.push_back(val);
            // return true;
        // }
        // return 0;
    }
    
    int popFront() {
        if(dq.size()>0){
            int x=dq.front();
            dq.pop_front();
            return x;
        }
        return -1;
    }
    
    int popMiddle() {
        int sz=dq.size();
        if(sz==0){
            return -1;
        }
        int c=sz;
        sz=ceil(sz/2.0);
        // sz-=1;
        stack<int>st;
        while(sz--){
            int x=dq.back();
            dq.pop_back();
            st.push(x);
        }
        int x=-1;
        if(c%2==0){
            x=dq.back();
            dq.pop_back();
        }
        else{
            x=st.top();
            st.pop();
        }
        while(!st.empty()){
            dq.push_back(st.top());
            st.pop();
        }
        return x;
    }
    
    int popBack() {
        if(dq.size()>0){
            int x=dq.back();
            dq.pop_back();
            return x;
        }
        return -1;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */