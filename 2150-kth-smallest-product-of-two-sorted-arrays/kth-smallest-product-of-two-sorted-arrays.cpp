class Solution {
    long long count1(vector<int>& nums1, vector<int>& nums2, long long prod){
        long long count=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]>=0){
                int low=0;
                int high=nums2.size()-1;
                int temp=-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if((long long)nums1[i]*(long long)nums2[mid]<=prod){
                        temp=mid;
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
                count+=temp+1;
            }
            else{
                int low=0;
                int high=nums2.size()-1;
                int temp=nums2.size();
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if((long long)nums1[i]*(long long)nums2[mid]<=prod){
                        temp=mid;
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                count+=(nums2.size()-temp);
            }
        }
        return count;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low=-1e10;
        long long high=1e10;
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(count1(nums1,nums2,mid)>=k){
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