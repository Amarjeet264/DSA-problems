class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int maxi = 0;
        for(int i =0;i<arr.size();i++){
            int len = 1;
            bool great = 1;
            for(int j = i+1;j<arr.size();j++){
                if(arr[j]>arr[j-1]&&great){
                    len++;
                }
                else if(arr[j]<arr[j-1]&&!great){
                    len++;
                }
                else{
                    break;
                }
                great = !great;
            }
            maxi = max(maxi,len);
            len = 1;
            great = 0;
            for(int j = i+1;j<arr.size();j++){
                if(arr[j]>arr[j-1]&&great){
                    len++;
                }
                else if(arr[j]<arr[j-1]&&!great){
                    len++;
                }
                else{
                    break;
                }
                great = !great;
            }
            maxi = max(maxi,len);
        }
        return maxi;
    }
};