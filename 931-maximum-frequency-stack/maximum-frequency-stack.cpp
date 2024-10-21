class FreqStack {
    int id = 0;
    unordered_map<int, int> ele;  // Frequency of each element
    set<pair<int, pair<int, int>>> st;  // Store (-frequency, -id, element) to handle sorting
    map<int, vector<int>> idx;  // Store insertion order (id) for each element

public:
    FreqStack() {}
    
    void push(int val) {
        ele[val] += 1;  // Increase frequency of element
        st.insert({-ele[val], {-id, val}});  // Insert into set with (-frequency, -id, val)
        idx[val].push_back(id);  // Store the id for the element
        id++;  // Increment id for next element
    }
    
    int pop() {
        // Get the element with highest frequency and latest insertion order
        auto maxP = *st.begin();
        st.erase(maxP);  // Remove the entry from the set
        int val = maxP.second.second;  // The value of the element to pop

        // Remove the latest index for the popped element
        idx[val].pop_back();
        
        // Decrease the frequency of the element
        ele[val]--;
        
        // If the frequency drops to 0, remove it completely
        if (ele[val] == 0) {
            ele.erase(val);
            idx.erase(val);
        } else {
            // Insert updated frequency and latest id into the set
            int newId = idx[val].back();  // Get the new latest id after popping
            st.insert({-ele[val], {-newId, val}});
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
