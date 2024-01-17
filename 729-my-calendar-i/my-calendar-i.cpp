class MyCalendar {
    set<pair<int,int>>st;
public:
    bool book(int start, int end) {
        auto it=st.lower_bound({start,end});
        // cout<<it->first<<" "<<it->second<<endl;
        if((it!=st.end()&&!(it->first>=end))||(it!=st.begin()&&!(prev(it)->second<=start))){
            return false;
        }
        st.insert({start,end});
        return 1;
    }
};