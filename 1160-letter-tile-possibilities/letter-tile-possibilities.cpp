class Solution {
    set<string>st;
    vector<int>vis;
    void find(string &temp,int i,string &nums){
        if(i>=nums.size()){
            st.insert(temp);
            return;
        }
        find(temp,i+1,nums);
        // if(temp.size()==0||nums[i]>=temp.back()){
        for(int j=0;j<nums.size();j++){
            if(!vis[j]){
                vis[j]=1;
                temp.push_back(nums[j]);
                find(temp,i+1,nums);
                temp.pop_back();
                vis[j]=0;
            }
        }
        // }
    }
public:
    int numTilePossibilities(string tiles) {
        string temp="";
        vis.resize(tiles.size());
        find(temp,0,tiles);
        return st.size()-1;
    }
};