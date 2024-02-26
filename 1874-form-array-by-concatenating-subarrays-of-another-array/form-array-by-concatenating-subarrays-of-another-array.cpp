class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n=nums.size();
        int g=0;
        int i=0;
        while(i<n){
            int sz=groups[g].size();
            int k=0;
            bool mila=false;
            for(int j=i;j<i+sz;j++){
                if(j>=n)return 0;
                if(groups[g][k]==nums[j]){
                    k++;
                }
                if(k==sz){
                    mila=true;
                    break;
                }
            }
            if(g==groups.size()-1&&mila){
                return 1;
            }
            if(mila){
                i=i+sz;
                g++;
            }
            else{
                i++;
            }
        }
        return 0;
    }
};