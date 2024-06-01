class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                for(int k=j;k<arr.size();k++){
                    int a=arr[i];
                    for(int x=i+1;x<=j-1;x++){
                        a=a^arr[x];
                    }
                    int b=arr[j];
                    for(int x=j+1;x<=k;x++){
                        b=b^arr[x];
                    }
                    if(a==b){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};