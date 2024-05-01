class Solution {
    string con(int z){
        string s="";
        while(z){
            if(z%2==0){
                s+='0';
            }
            else{
                s+='1';
            }
            z=z/2;
        }
        return s;
    }
    long long binaryToInteger(std::string binary) {
        long long decimal = 0;
        long long length = binary.length();

        for (int i = 0; i < length; i++) {
            if (binary[length - i - 1] == '1') {
                decimal += pow(2, i);
            }
        }

        return decimal;
    }
public:
    long long minEnd(int n, int x) {
        n-=1;
        string first=con(x);
        string last=con(n);
        // reverse(last.begin(),last.end());
        // cout<<first<<endl;
        // cout<<last<<endl;
        int i=0;
        int j=0;
        while(i<first.size()&&j<last.size()){
            if(first[i]=='0'){
                first[i++]=last[j++];
            }
            else{
                i++;
            }
        }
        while(j<last.size()){
            first.push_back(last[j]);
            j++;
        }
        reverse(first.begin(),first.end());
        long long ans=binaryToInteger(first);
        return ans;
    }
};