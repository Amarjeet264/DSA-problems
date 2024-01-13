class Solution {
// 0 2
// 1 1
// 2 1
// 3 0
// 4 1
// 5 0
// 6 0
// 8 1
// 9 0
// 10 0
public:
    vector<string> readBinaryWatch(int on) {
        if(on>8){
            return {};
        }
        vector<string>ans;
        for(int i=0;i<12;i++){
            string s="";
            int x=on;
            if(i!=0){
                if((i==1||i==2||i==4||i==8)){
                    x-=1;
                }
                else if((i==3||i==5||i==9||i==6||i==10)){
                    x-=2;
                }
                else if((i==7||i==11)){
                    x-=3;
                }
            }
            if(x<0)continue;
            s+=to_string(i);
            s+=':';
            string z=s;
            if(x==0){
                s+="00";
                ans.push_back(s);
            }
            else {
                for(int j=1;j<=59;j++){
                    s=z;
                    if(x==1){
                        if(j==1||j==2||j==4||j==8){
                            s+="0";
                            s+=to_string(j);
                        }
                        else if(j==16||j==32){
                            s+=to_string(j);
                        }
                    }
                    else if(x==2){
                        if(j==3||j==5||j==9||j==6){
                            s+='0';
                            s+=to_string(j);
                        }
                        else if(j==17||j==33||j==10||j==12||j==18||j==34||j==20||j==36||j==24||j==40||j==48){
                            s+=to_string(j);
                        }
                    }
                    else if(x==3){
                        if(j==7){
                            s+='0';
                            s+=to_string(j);
                        }
                        else if(j==21||j==37||j==41||j==42||j==44||j==11||j==19||j==35||j==14||j==22||j==38||j==56||j==25||j==28||j==26||j==13||j==49||j==50||j==52){
                            s+=to_string(j);
                        }
                    }
                    else if(x==4){
                        if(j==53||j==57||j==58||j==45||j==29||j==15||j==23||j==39||j==27||j==43||j==51||j==30||j==46||j==54){
                            s+=to_string(j);
                        }
                    }
                    else if(x==5){
                        if(j==31||j==47||j==55||j==59){
                            s+=to_string(j);
                        }
                    }
                    if(s.size()>z.size())ans.push_back(s);
                }
            }
        }
        return ans;
    }
};