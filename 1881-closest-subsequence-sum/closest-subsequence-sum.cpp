class Solution {
    void solve(vector<int>&nums,int i,int end,int sum,vector<int>&x){
        if(i>=end){
            x.push_back(sum);
            return;
        }
        solve(nums,i+1,end,sum,x);
        solve(nums,i+1,end,sum+nums[i],x);
    }
    void find(vector<int>&left,vector<int>&right,int &mini,int goal){
        int i=0;
        int j=right.size()-1;
        while(i<left.size()&&j>=0){
            int sum=left[i]+right[j];
            mini=min(mini,abs(goal-sum));
            if(sum<goal){
                i++;
            }
            else if(sum>goal){
                j--;
            }
            else break;
        }
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        int mini=INT_MAX;
        vector<int>left,right;
        solve(nums,0,n/2+1,0,left);
        solve(nums,n/2+1,n,0,right);
        for(int i=0;i<left.size();i++){
            mini=min(mini,abs(goal-left[i]));
        }
        for(int i=0;i<right.size();i++){
            mini=min(mini,abs(goal-right[i]));
        }
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        find(left,right,mini,goal);
        return mini;
    }
};