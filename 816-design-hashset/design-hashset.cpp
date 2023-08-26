class MyHashSet {
    unordered_map<int,int>mp;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        mp[key]++;
    }
    
    void remove(int key) {
        if(!contains(key))return;
        mp.erase(key);
    }
    
    bool contains(int key) {
        if(mp.find(key)==mp.end())return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */