class Solution {
    bool isposs(int day,int m,int k,vector<int>&bloom){
        int basket=0;
        int cnt_Bloom=0;
        for(int i=0;i<bloom.size();i++){
            if(bloom[i]<=day){
                cnt_Bloom++;
            }
            else{
                basket+=(cnt_Bloom/k);
                cnt_Bloom=0;
            }
        }
        basket+=(cnt_Bloom/k);
        return basket>=m;
    }
public:
    int minDays(vector<int>& bloom, int m, int k) {
        int low=1;
        int high=0;
        for(auto it:bloom){
            high=max(high,it);
        }
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isposs(mid,m,k,bloom)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};