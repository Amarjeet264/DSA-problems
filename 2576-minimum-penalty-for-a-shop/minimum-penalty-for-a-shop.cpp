class Solution {
public:
    int bestClosingTime(string custo) {
        int maxi=0;
        int profit=0;
        int ans=0;
        for(int i=0;i<custo.size();i++){
            if(custo[i]=='Y'){
                profit++;
                if(profit>maxi){
                    maxi=profit;
                    ans=i+1;
                }
            }
            else{
                profit--;
            }
        }
        return ans;
    }
};