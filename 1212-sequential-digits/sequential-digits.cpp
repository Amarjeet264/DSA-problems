class Solution {
    int convert(long long n) {  
        return log10(n) + 1;  
    } 
    vector<int>ans;
    string s="123456789";
    void calc(int n,int low ,int high){
        for(int i=0;i<=9-n;i++){
            string temp=s.substr(i,n);
            int x=stoi(temp);
            if(x>=low&&x<=high){
                ans.push_back(x);
            }
            else if(x>high)break;
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        int x=convert(low);
        int y=convert(high);
        for(int i=x;i<=y;i++){
            calc(i,low,high);
        }
        return ans;
    }
};