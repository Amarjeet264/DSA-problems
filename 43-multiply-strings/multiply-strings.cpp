class Solution {
public:
    string multiply(string num1, string num2) {
        string ans="";
        int cnt=0;
        for(int i=num2.size()-1;i>=0;i--){
            int ele=num2[i]-'0';
            if(ans.size()==0){
                int carry=0;
                for(int k=num1.size()-1;k>=0;k--){
                    int x=num1[k]-'0';
                    int mul=ele*x;
                    // cout
                    mul+=carry;
                    int num=mul%10;
                    // cout<<mul<<" ";
                    ans.push_back(num+'0');
                    carry=mul/10;
                }
                if(carry){
                    ans.push_back(carry+'0');
                }
                reverse(ans.begin(),ans.end());
                cout<<ans<<endl; 
            }
            else{
                string nayi="";
                int carry=0;
                for(int k=num1.size()-1;k>=0;k--){
                    int x=num1[k]-'0';
                    int mul=ele*x;
                    // cout
                    mul+=carry;
                    int num=mul%10;
                    // cout<<mul<<" ";
                    nayi.push_back(num+'0');
                    carry=mul/10;
                }
                if(carry){
                    nayi.push_back(carry+'0');
                }
                reverse(nayi.begin(),nayi.end());
                cout<<nayi<<endl;
                int x=cnt;
                string final="";
                int j=ans.size()-1;
                while(x--){
                    final.push_back(ans[j]);
                    j--;
                }
                cout<<final<<endl;
                int k=nayi.size()-1;
                string dusri="";
                int car=0;
                while(k>=0&&j>=0){
                    int add=ans[j]-'0'+nayi[k]-'0'+car;
                    int p=add%10;
                    dusri.push_back(p+'0');
                    car=add/10;
                    k--;
                    j--;
                }
                while(k>=0){
                    int add=nayi[k]-'0'+car;
                    int p=add%10;
                    dusri.push_back(p+'0');
                    car=add/10;
                    k--;
                }
                if(car){
                    dusri.push_back(car+'0');
                }
                reverse(dusri.begin(),dusri.end());
                cout<<dusri<<endl;
                ans=dusri;
                reverse(final.begin(),final.end());
                ans+=final;
                cout<<ans<<" ";
                // for(int h=0;h<dusri.size())
            }
            cout<<endl<<endl;
            cnt++;
        }
        string f="";
        int i=0;
        bool iszer=0;
        while(i<ans.size()){
            if(ans[i]=='0'){
                iszer=1;
            }
            else{
                break;
            }
            i++;
        }
        if(i==ans.size()&&iszer){
            return "0";
        }
        return ans;
    }
};