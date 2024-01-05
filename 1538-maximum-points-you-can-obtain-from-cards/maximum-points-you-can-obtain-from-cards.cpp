class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int sum=0;
        if(card.size()<=k){
            for(int i=0;i<n;i++){
                sum+=card[i];
            }
            return sum;
        }
        int i=0;
        while(i<k){
            sum+=card[i];
            i++;
        }
        i--;
        int maxi=sum;
        int j=card.size()-1;
        while(k--){
            sum-=card[i];
            sum+=card[j];
            i--;
            j--;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};