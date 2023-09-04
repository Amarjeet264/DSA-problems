class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        long long x=0;
        for(int i=0;i<nums.size();i++){
            x+=nums[i];
            pq.push((double)nums[i]);
        }
        double half=(double)x/2;
        double sum=0;
        int cnt=0;
        while(!pq.empty()&&sum<half){
            double t=pq.top();
            cout<<t<<" ";
            pq.pop();
            sum+=(double)t/2;
            if(t>0){
                pq.push(t/2);
            }
            cnt++;
        }
        return cnt;
    }
};