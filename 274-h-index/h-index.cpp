class Solution {
public:
    int hIndex(vector<int>& cit) {
       sort(cit.begin(),cit.end());
       int low=0;
        int high=cit.size()-1;
        int maxi=0;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(cit[mid]>=cit.size()-mid){
                ans=cit.size()-mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};