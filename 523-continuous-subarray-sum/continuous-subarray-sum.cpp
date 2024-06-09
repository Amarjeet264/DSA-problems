class Solution {
public:
    static bool checkSubarraySum(vector<int>&arr, int K) {
        int N=arr.size();
        unordered_map<int,int>mp;
	    int rem=0;
	    mp[0]=-1;
	    int sum=0;
	    int cnt=0;
	    for(int i=0;i<N;i++){
	        sum+=arr[i];
            // if(sum==0)continue;
	        rem=sum%K;
	        if(rem<0){
	            rem=rem+K;
	        }
	        if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>1)
	               return true;
	        }
	        if(mp.find(rem)==mp.end())mp[rem]=i;
	    }
	    return false;
    }
      
};
