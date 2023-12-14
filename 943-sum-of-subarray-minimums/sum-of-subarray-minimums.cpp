#include<bits/stdc++.h>
class Solution {
    vector<int> pse(vector<int>&a){
        vector<int>p;
        int n = a.size();
        stack<int>s;
        for(int i=0; i<n; i++){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
            }
            if(!s.empty()){
                p.push_back(s.top());
            }
            else{
                p.push_back(-1);
            }
            s.push(i);
        }
        return p;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int m = 1e9+7;
        vector<int>prevsmall=pse(arr);
        int n=arr.size();
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++){
            
            if(prevsmall[i] == -1) ans[i] = ((i+1)*arr[i])%m;
            else ans[i]=(ans[prevsmall[i]]+(arr[i]*(i-prevsmall[i]))%m)%m;
            
        }
        
        int sum=0;
        for(auto x:ans) sum=(sum+x)%m;
        return sum;
    }
};