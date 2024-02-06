class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top=0;
        int bottom=n-1;
        int right=n-1;
        int left=0;
        int x=1;
        vector<vector<int>>vec(n,vector<int>(n,0));
        while(left<=right&&top<=bottom){
            for(int i=left;i<=right;i++){
                vec[top][i]=x;
                cout<<x<<" ";
                x++;
            }
            cout<<"first"<<endl;
            top++;
            for(int i=top;i<=bottom;i++){
                cout<<x<<" ";
                vec[i][right]=x;
                x++;
            }
            right--;
            cout<<"second"<<endl;
            for(int i=right;i>=left;i--){
                vec[bottom][i]=x;
                cout<<x<<" ";
                x++;
            }
            cout<<"third"<<endl;
            bottom--;
            for(int i=bottom;i>=top;i--){
                cout<<x<<" ";
                vec[i][left]=x;
                x++;
            }
            left++;
            cout<<"ffff"<<endl;
        }
        return vec;
    }
};