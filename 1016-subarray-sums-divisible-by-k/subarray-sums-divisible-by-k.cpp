class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int K) {
        int N=arr.size();
        vector<int>mp(K,0);
	    int rem=0;
	    mp[0]++;
	    int sum=0;
	    int cnt=0;
	    for(int i=0;i<N;i++){
	        sum+=arr[i];
	        rem=sum%K;
	        if(rem<0){
	            rem=rem+K;
	        }
	        if(mp[rem]!=0){
	            cnt+=mp[rem];
	        }
	        mp[rem]++;
	    }
	    return cnt;
    }
};