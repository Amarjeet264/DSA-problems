class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        map<vector<int>,int>mp;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            vector<int>x;
            x.push_back(nums[i]);
            int j=i+1;
            int k=0;
            while(j<nums.size()&&k<pattern.size()){
                if(pattern[k]==1){
                    if(nums[j]>x.back()){
                        x.push_back(nums[j]);
                    }
                    else{
                        break;
                    }
                }
                else if(pattern[k]==0){
                    if(nums[j]==x.back()){
                        x.push_back(nums[j]);
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(nums[j]<x.back()){
                        x.push_back(nums[j]);
                    }
                    else{
                        break;
                    }
                }
                j++;
                k++;
            }
            // for(int l=0;l<x.size();l++){
            //     cout<<x[l]<<" ";
            // }
            // cout<<endl;
            if(x.size()==pattern.size()+1){
                cnt++;
                mp[x]++;
            }
        }
        return cnt;
    }
};