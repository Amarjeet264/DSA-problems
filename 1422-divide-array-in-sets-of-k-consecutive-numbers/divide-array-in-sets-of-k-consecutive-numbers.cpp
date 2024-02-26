class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        priority_queue<int>pq;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            pq.push(-it.first);
        }
        while(!pq.empty()){
            int x=k;
            vector<int>dup;
            int prev=-1;
            while(x>0){
                int ele=-pq.top();
                pq.pop();
                if(prev==-1)prev=ele;
                else if(ele-prev!=1)return 0;
                x--;
                if(pq.empty()&&x>0){
                    return 0;
                }
                mp[ele]--;
                if(mp[ele]>0){
                    dup.push_back(ele);
                }
                prev=ele;
            }
            // cout<<endl;
            for(int i=0;i<dup.size();i++){
                pq.push(-dup[i]);
            }
        }
        return 1;
    }
};