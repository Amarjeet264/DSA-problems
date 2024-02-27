class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int>rad;
        queue<int>dir;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                rad.push(i);
            }
            else{
                dir.push(i);
            }
        }
        while(!dir.empty()&&!rad.empty()){
            if(dir.front()<rad.front()){
                dir.push(n++);
            }
            else{
                rad.push(n++);
            }
            dir.pop();
            rad.pop();
        }
        if(!rad.empty()){
            return "Radiant";
        }
        return "Dire";
    }
};