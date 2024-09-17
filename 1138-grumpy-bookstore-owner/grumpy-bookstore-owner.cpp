class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        for(int i=0;i<grumpy.size();i++){
            if(grumpy[i]==0){
                sum+=customers[i];
            }
        }
        int maxi=sum;
        int nayasum=sum;
        int i=0;
        int j=0;
        while(j<customers.size()){
            if(grumpy[j]==1){
                nayasum+=customers[j];
                while(i<j&&j-i+1>minutes){
                    if(grumpy[i]==1){
                        nayasum-=customers[i];
                    }
                    i++;
                }
                maxi=max(maxi,nayasum);
            }
            // else if(i==j){
            //     i++;
            // }
            j++;
        }
        return maxi;
    }
};