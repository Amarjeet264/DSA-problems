class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        int i=0;
        int j=0;
        int n=arr.size();
        while(j<n){
            if(arr[j]%2!=0){
                count++;
                if(count==3){
                    return true;
                }
            }
            else{
                count=0;
            }
            j++;
        }
     return false;
    }
};