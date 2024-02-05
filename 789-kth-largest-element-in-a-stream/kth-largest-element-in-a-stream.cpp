class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int z;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        z=k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>z){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */