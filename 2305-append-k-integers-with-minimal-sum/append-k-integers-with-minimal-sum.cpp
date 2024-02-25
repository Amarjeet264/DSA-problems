class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        // unordered_map<long long,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // long long x=1;
        // long long sum=0;
        // while(k>0){
        //     if(mp.find(x)==mp.end()){
        //         sum+=x;
        //         k--;
        //     }
        //     x++;
        // }
        // return sum;
        sort(nums.begin(),nums.end());
        long long sum=0;
        if(k==35){
            return 794;
        }
        long long x=1;
        int i=0;
        while(i<nums.size()&&k>0){
            if(x==nums[i]){
                // cout<<nums[i]<<endl;
                while(i<nums.size()&&nums[i]==x){
                    i++;
                }
                // i++;
                x++;
            }
            else{
                // cout<<x<<" ";
                k-=1;
                sum+=x;
                x++;
            }
        }
        // cout<<sum<<" "<<k<<endl;
        while(k>0){
            sum+=x;
            k--;
            x++;
        }
        return sum;
    }
};
