class Solution {
    static bool comp(string &a,string &b){
        return stoi(a)<stoi(b);
    }
    int mystoi(const std::string& str) {
    int result = 0;
    int sign = 1;
    size_t i = 0;

    // Handle optional sign
    if (str[i] == '-') {
        sign = -1;
        ++i;
    } else if (str[i] == '+') {
        ++i;
    }

    // Process digits
    while (i < str.size() && std::isdigit(str[i])) {
        result = result * 10 + (str[i] - '0');
        ++i;
    }
    return sign * result;
}
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>&times) {
        sort(times.begin(),times.end());
        int i=0;
        vector<string>ans;
        while(i<times.size()){
            string now=times[i][0];
            vector<string>currtime;
            while(i<times.size()&&times[i][0]==now){
                currtime.push_back((times[i][1]));
                i++;
            }
            sort(currtime.begin(),currtime.end(),comp);
            // if(now=="aywtqh"){
            //     for(int i=0;i<currtime.size();i++){
            //         cout<<currtime[i]<<endl;
            //     }
            // }
            if(currtime.size()<3)continue;
            else{
                for(int k=0;k<currtime.size();k++){
                    string s="";
                    s+=currtime[k][0];
                    s+=currtime[k][1];
                    int starth=mystoi(s);
                    s="";
                    s+=currtime[k][2];
                    s+=currtime[k][3];
                    // cout<<s<<endl;
                    int startmin=mystoi(s);
                    // cout<<startmin<<endl;
                    int j=k+1;
                    bool can=0;
                    int cnt=1;
                    while(j<currtime.size()){
                        s="";
                        s+=currtime[j][0];
                        s+=currtime[j][1];
                        int x=mystoi(s);
                        // if(now=="aywtqh")cout<<starth<<" "<<startmin<<endl;
                        if(x-starth<1){
                            cnt++;
                        }
                        else{
                            s="";
                            s+=currtime[j][2];
                            s+=currtime[j][3];
                            int y=mystoi(s);
                            if(x-starth==1&&y-startmin<0){
                                    if(startmin==19)cout<<"ha"<<now<<endl;
                                    cnt++;
                            }
                            else{
                                cnt=1;
                                starth=x;
                                startmin=y;
                            }
                        }
                        if(cnt==3){
                            can=1;
                            break;
                        }
                        j++;
                    }
                    if(can){
                         ans.push_back(now);
                         break;
                    }
                }
            }
        }
        return ans;
    }
};