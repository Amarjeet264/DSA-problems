class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            sort(words[i].begin(),words[i].end());
            int x=1;
            char ch=words[i][0];
            // cout<<ch<<" ";
            int j=1;
            while(j<words[i].size()&&ch==words[i][j]){
                // cout<<i<<" "<<j<<endl;
                j++;
                x++;
            }
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        for(auto it:ans){
            // cout<<it<<" ";
        }
        vector<int>final;
        for(int i=0;i<queries.size();i++){
            sort(queries[i].begin(),queries[i].end());
            int x=1;
            char ch=queries[i][0];
            int j=1;
            while(j<queries[i].size()&&ch==queries[i][j]){
                j++;
                x++;
            }
            // cout<<x<<endl;
            int low=0;
            int high=ans.size()-1;
            int pos=ans.size();
            while(low<=high){
                int mid=(low+high)/2;
                if(ans[mid]>x){
                    pos=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            // cout<<pos<<" ";
            final.push_back(ans.size()-pos);
        }
        return final;
    }
};