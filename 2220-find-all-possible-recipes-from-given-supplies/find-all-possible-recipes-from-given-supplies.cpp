class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int>mp;
        for(int i=0;i<supplies.size();i++){
            mp[supplies[i]]=i;
        }
        unordered_map<string,int>mp1;
        unordered_map<int,string>mp2;
        int maxi=supplies.size()-1;
        for(int i=0;i<recipes.size();i++){
            if(mp.find(recipes[i])!=mp.end()){
                mp1[recipes[i]]=mp[recipes[i]];
            }
            else{
                maxi=supplies.size()+i;
                mp1[recipes[i]]=supplies.size()+i;
                mp2[maxi]=recipes[i];
            }
        }
        vector<int>adj[maxi+1];
        vector<int>in(maxi+1);
        for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                if(mp.find(ingredients[i][j])==mp.end()){
                    adj[mp1[ingredients[i][j]]].push_back(mp1[recipes[i]]);
                    in[mp1[recipes[i]]]++;
                }
            }
        }
        queue<int>q;
        for(int i=0;i<=maxi;i++){
            if(in[i]==0&&mp2.count(i)>0){
                q.push(i);
            }
        }
        vector<string>ans;
        while(!q.empty()){
            int fr=q.front();
            q.pop();
            if(mp2[fr]!="")
            ans.push_back(mp2[fr]);
            for(auto it:adj[fr]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};