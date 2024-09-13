class Solution {
    bool isposs(long long diff,vector<int>start,long long d){
       for(int i = 1;i<start.size();i++){
            if((start[i]-start[i-1])>=diff){
                continue;
            }
            else if((start[i]+d-start[i-1])>=diff){
                start[i] += (diff-(start[i]-start[i-1]));
            }
            else{
                return 0;
            }
       }
       return 1;
    }
public:
    int maxPossibleScore(vector<int>& start, int d) {
        int ans = 0;
        int low = 0;

        sort(start.begin(),start.end());
        long long high = start[start.size()-1]-start[0]+d;
        while(low<=high){
            long long mid = (low+high)/2;
            if(isposs(mid,start,d)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            // cout<<mid<<endl;
        }
        return ans;
    }
};