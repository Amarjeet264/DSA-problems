class FreqStack {
    int id = 0;
    unordered_map<int,int>ele;
    set<pair<int,pair<int,int>>>st;
    map<int,vector<int>>idx;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        ele[val] += 1;
        st.insert({-ele[val],{-id,val}});
        idx[val].push_back(id);
        id++;
    }
    
    int pop() {
        pair<int,pair<int,int>>maxP = *st.begin();
        st.erase(maxP);
        int val = maxP.second.second;
        int newF = -maxP.first;
        idx[val].pop_back();
        if(newF-1==0){
            idx.erase(val);
            ele.erase(val);
        }
        else{
            ele[val] -= 1;
            int newIdx = idx[val].back();
            st.insert({-(newF-1),{-newIdx,val}});
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */