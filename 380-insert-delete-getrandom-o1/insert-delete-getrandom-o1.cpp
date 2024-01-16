class RandomizedSet {
    vector<int>list;
    unordered_map<int,int>mp;
public:
    RandomizedSet() {
          
    }
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        int idx=list.size();
        mp[val]=idx;
        list.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        int idx=mp[val];
        int lastval=list.back();
        list[idx]=lastval;
        list.pop_back();
        mp[lastval]=idx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex =rand()%list.size();
        return list[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */