class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        int m = rolls.size();
        for(int i= 0;i<m;i++){
            sum+=rolls[i];
        }
        if((6*n+sum)/(n+m)<mean){
            return {};
        }
        vector<int>ans;
        int x = n;
        while((n+sum)/(m+x)<mean){
            sum+=6;
            ans.push_back(6);
            n--;
        }
        if((sum+n)==(m+x)*mean){
            while(n--){
                ans.push_back(1);
            }
            return ans;
        }
        // cout<<sum<<endl;
        if(ans.size()>=1){
            ans.pop_back();
            sum-=6;
            n++;
        }
        while(n>1){
            ans.push_back(1);
            sum++;
            n--;
        }
        for(int i = 1;i<=6;i++){
            if((sum+i)==(m+x)*mean){
                ans.push_back(i);
                sum+=i;
                break;
            }
        }
        if(sum!=(m+x)*mean){
            return {};
        }
        return ans;
    }
};