class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>first(n);
        vector<int>second(n);
        vector<int>third(n);
        for(int i=0;i<n;i++){
            if(obstacles[i]==1){
                first[i]=1;
            }
            else if(obstacles[i]==2){
                second[i]=1;
            }
            else if(obstacles[i]==3){
                third[i]=1;
            }
        }
        int last=n;
        for(int i=n-1;i>=0;i--){
            if(first[i]==1){
                last=i;
            }
            first[i]=last;
        }
        last=n;
        for(int i=n-1;i>=0;i--){
            if(second[i]==1){
                last=i;
            }
            second[i]=last;
        }
        last=n;
        for(int i=n-1;i>=0;i--){
            if(third[i]==1){
                last=i;
            }
            third[i]=last;
        }
        int i=0;
        int lane=2;
        int cnt=0;
        while(i<n){
            if(lane==2){
                if(i+1<n&&obstacles[i+1]==2){
                    if(first[i]>=third[i]){
                        lane=1;
                        // cout<<i<<" ";
                        cnt++;
                        // i++;
                    }
                    else{
                        // cout<<i<<" ";
                        cnt++;
                        lane=3;
                        // i++;
                    }
                }
                else{
                    i++;
                }
            }
            else if(lane==3){
                if(i+1<n&&obstacles[i+1]==3){
                    if(first[i]>=second[i]){
                        // cout<<i<<" ";
                        cnt++;
                        lane=1;
                        // i++;
                    }
                    else{
                        cnt++;
                        lane=2;
                        // i++;
                    }
                }
                else{
                    i++;
                }
            }
            else{
                if(i+1<n&&obstacles[i+1]==1){
                    if(third[i]>=second[i]){
                        cnt++;
                        lane=3;
                        // i++;
                    }
                    else{
                        cnt++;
                        lane=2;
                        // i++;
                    }
                }
                else{
                    i++;
                }
            }
        }
        return cnt;
    }
};