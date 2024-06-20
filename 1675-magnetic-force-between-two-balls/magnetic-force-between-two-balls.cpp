class Solution {
    bool isposs(int mid,int m,vector<int>&pos){
        int last=-1;
        int cnt=0;
        for(int i=0;i<pos.size();i++){
            if(last==-1||pos[i]-last>=mid){
                last=pos[i];
                cnt++;
            }
        }
        return cnt>=m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int low=0;
        sort(position.begin(),position.end());
        int high=position[position.size()-1];
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isposs(mid,m,position)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};