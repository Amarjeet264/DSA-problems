class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        sort(skills.begin(),skills.end());
        int sum=INT_MAX;
        long long ans=0;
        int i=0;
        int j=skills.size()-1;
        while(i<j){
            if(sum==INT_MAX){
                sum=skills[i]+skills[j];
                ans=ans+(skills[i]*skills[j]);
                i++;
                j--;
            }
            else{
                if(skills[i]+skills[j]!=sum){
                    return -1;
                }
                else{
                    ans=ans+(skills[i]*skills[j]);
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};