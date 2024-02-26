class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        priority_queue<pair<int,int>>pq;
        vector<int>ans(nums1.size(),-1);
        for(int i=0;i<nums2.size();i++){
            pq.push({nums2[i],i});
        }
        int i=nums1.size()-1;
        while(!pq.empty()){
            if(pq.top().first<nums1[i]){
                ans[pq.top().second]=nums1[i];
                i--;
            }
            pq.pop();
        }
        for(int j=0;j<nums1.size();j++){
            if(ans[j]==-1){
                ans[j]=nums1[i];
                i--;
            }
        }
        return ans;
    }
};