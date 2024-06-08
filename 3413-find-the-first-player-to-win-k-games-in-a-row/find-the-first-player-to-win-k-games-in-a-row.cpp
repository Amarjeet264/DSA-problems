class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        deque<int>dq;
        for(int i=0;i<skills.size();i++){
            dq.push_back(i);
        }
        bool winner=true;
        unordered_map<int,int>mp;
        if(k>=skills.size()){
            int maxi=0;
            for(int i=1;i<skills.size();i++){
                if(skills[maxi]<skills[i]){
                    maxi=i;
                }
            }
            return maxi;
        }
        while(winner){
            int x=dq.front();
            dq.pop_front();
            int y=dq.front();
            dq.pop_front();
            if(skills[x]>skills[y]){
                mp[x]++;
                dq.push_front(x);
                dq.push_back(y);
                if(mp[x]==k){
                    return x;
                }
            }
            else{
                mp[y]++;
                if(mp[y]==k){
                    return y;
                }
                dq.push_front(y);
                dq.push_back(x);
            }
        }
        return -1;
    }
};