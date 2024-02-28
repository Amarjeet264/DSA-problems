class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<int,string>mp;
        mp[0]="abcde";
        mp[1]="fghij";
        mp[2]="klmno";
        mp[3]="pqrst";
        mp[4]="uvwxy";
        mp[5]="z";
        unordered_map<int,string>mp1;
        mp1[0]="afkpuz";
        mp1[1]="bglqv";
        mp1[2]="chmrw";
        mp1[3]="dinsx";
        mp1[4]="ejoty";
        int row=0;
        string ans="";
        int col=0;
        for(int i=0;i<target.size();i++){
            int x=-1;
            int y=-1;
            for(int j=0;j<6;j++){
                if(mp[j].find(target[i]) != string::npos){
                    x=j;
                }
            }
            for(int j=0;j<5;j++){
                if(mp1[j].find(target[i]) != string::npos){
                    y=j;
                }
            }
            if(target[i]=='z'){
                if(row==5&&col==0){
                    ans+='!';
                    continue;
                }
                if(col!=0){
                    for(int j=col;j>0;j--){
                        ans+='L';
                    }
                }
                if(row<5){
                    for(int j=row;j<5;j++){
                        ans+='D';
                    }
                }
                ans+='!';
                row=x;
                col=y;
                continue;
            }
            if(x>=row){
                for(int j=row;j<x;j++){
                    ans+='D';
                }
            }
            else{
                for(int j=row;j>x;j--){
                    ans+='U';
                }
            }
            if(y>=col){
                for(int j=col;j<y;j++){
                    ans+='R';
                }
            }
            else{
                for(int j=col;j>y;j--){
                    ans+='L';
                }
            }
            row=x;
            col=y;
            ans+='!';
        }
        return ans;
    }
};