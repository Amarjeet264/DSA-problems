class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<res.size();i++){
            mp[res[i][0]-1].push_back(res[i][1]-1);
        }
        int ans=0;
        for(auto it:mp){
            vector<int>vec(10,0);
            for(auto i:it.second){
                vec[i]=1;
            }
            bool left=true;
            for(int j=1;j<5;j++){
                if(vec[j]==1){
                    left=false;
                }
            }
            bool right=true;
            for(int j=5;j<9;j++){
                if(vec[j]==1){
                    right=false;
                }
            }
            if(left==false&&right==false){
                bool beech=true;
                for(int j=3;j<7;j++){
                    if(vec[j]==1){
                        beech=false;
                    }
                }
                if(beech==true){
                    ans++;
                }
            }
            else{
                if(left==true&&right==true){
                    ans+=2;
                }
                else{
                    ans++;
                }
            }
        }
        return ans+(n-mp.size())*2;
    }
};