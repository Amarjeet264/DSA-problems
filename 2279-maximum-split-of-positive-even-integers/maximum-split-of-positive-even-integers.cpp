class Solution {
public:
    vector<long long> maximumEvenSplit(long long sum) {
        if(sum%2!=0)return {};
        vector<long long>ans;
        int count=2;
        while(sum-count>=0){
            ans.push_back(count);
            sum=sum-count;
            count=count+2;
        }
        if(sum==0)return ans;
        ans[ans.size()-1]+=sum;
        return ans;
    }
};