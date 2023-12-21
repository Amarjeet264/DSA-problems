class Solution {
    int largest(vector<int>&arr,int n){
        stack<int>st;
        vector<int>leftmin;
        vector<int>rightmin;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                leftmin.push_back(st.top());
            }
            else{
                leftmin.push_back(-1);
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                rightmin.push_back(st.top());
            }
            else{
                rightmin.push_back(-1);
            }
            st.push(i);
        }
        reverse(rightmin.begin(),rightmin.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(leftmin[i]==-1&&rightmin[i]==-1){
                ans=max(ans,n*arr[i]);
            }
            else if(leftmin[i]==-1){
                ans=max(ans,(i+1)*arr[i]+(rightmin[i]-i-1)*arr[i]);
            }
            else if(rightmin[i]==-1){
                ans=max(ans,(n-i-1)*arr[i]+(i-leftmin[i])*arr[i]);
            }
            else{
                ans=max(ans,(i-leftmin[i])*arr[i]+(rightmin[i]-i-1)*arr[i]);
            }
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>mat(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int j=0;j<mat[0].size();j++){
            if(matrix[0][j]=='1'){
                mat[0][j]=1;
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    mat[i][j]=1+mat[i-1][j];
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans=0;
        for(int i=0;i<mat.size();i++){
            ans=max(ans,largest(mat[i],matrix[0].size()));
        }
        return ans;
    }
};