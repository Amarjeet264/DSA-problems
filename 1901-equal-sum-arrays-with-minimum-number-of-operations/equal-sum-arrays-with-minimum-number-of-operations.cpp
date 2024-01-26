class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
       int s1=0;
       int s2=0;
       for(auto it:nums1){
           s1+=it;
       } 
       for(auto it:nums2){
           s2+=it;
       }
       if(s1>s2){
           swap(nums1,nums2);
       }
       int diff=abs(s2-s1);
       if(diff==0){
           return 0;
       }
       vector<int>arr;
       for(auto &it:nums1){
           arr.push_back(6-it);
       }
       for(auto &it:nums2){
           arr.push_back(it-1);
       }
       sort(arr.rbegin(),arr.rend());
    //    for(auto it:arr){
    //        cout<<it<<" ";
    //    }
       int ans=0;
       for(auto it:arr){
        //    cout<<it<<" ";
           diff-=it;
           ans++;
           if(diff<=0)return ans;
       }
       return -1;
    }
};