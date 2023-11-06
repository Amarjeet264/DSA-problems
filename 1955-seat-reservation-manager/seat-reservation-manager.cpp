class SeatManager {
    unordered_map<int,int>mp;
    priority_queue<int,vector<int>,greater<int>>pq;
public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        if(pq.empty())return -1;
        int x=pq.top();
        pq.pop();
        // mp[x]++;
        return x;
    }
    
    void unreserve(int seat) {
        // mp.erase(seat);
        pq.push(seat);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */