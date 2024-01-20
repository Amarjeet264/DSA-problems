#include<bits/stdc++.h>
class Solution {
    vector<int> nse(vector<int>&a){
        vector<int>n;
        stack<int>s;
        for(int i=a.size()-1; i>=0; i--){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
            }
            if(!s.empty()){
                n.push_back(s.top());
            }
            else{
                n.push_back(a.size());
            }
            s.push(i);
        }
        reverse(n.begin(), n.end());
        return n;
    }
    vector<int> pse(vector<int>&a){
        vector<int>p;
        int n = a.size();
        stack<int>s;
        for(int i=0; i<n; i++){
            while(!s.empty() && a[s.top()]>a[i]){
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
        int mod=1e9+7;
        long long total=0;
        vector<int>p = pse(arr);
        vector<int>n = nse(arr);
        int m = arr.size();
        long long int sum=0;
        for(int i=0; i<m; i++){
            int x = p[i];
            int y = n[i];
            if(x==-1){
                x=i+1;
            }
            else{
                x=i-p[i];
            }
            if(y==m){
                y=m-i;
            }
            else{
                y=n[i]-i;
            }
            total=(total%mod+(long long)arr[i]*(x*y))%mod;
        }
       return total%mod;

    }
};