class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftmax(n,-1);
        vector<int>rightmax(n,-1);
        int maxi=height[0];
        for(int i=1;i<n;i++){
            if(height[i]<maxi){
                leftmax[i]=maxi;
            }
            maxi=max(maxi,height[i]);
        }
        maxi=height[n-1];
        for(int i=n-1;i>=0;i--){
            if(height[i]<maxi){
                rightmax[i]=maxi;
            }
            maxi=max(maxi,height[i]);
        }
        int x=0;
        for(int i=1;i<=n-2;i++){
            if(leftmax[i]!=-1&&rightmax[i]!=-1){
                cout<<i<<" "<<leftmax[i]<<" "<<rightmax[i]<<endl;
                x+=min(leftmax[i],rightmax[i])-height[i];
            }
        }
        return x;
    }
};