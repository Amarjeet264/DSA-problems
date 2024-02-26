class Solution {
    int sum=0;
    int inc(int node,vector<int>&cost,int n){
        if(node>cost.size()){
            return 0;
        }
        int left=inc(2*node,cost,n);
        int right=inc(2*node+1,cost,n);
        sum+=abs(left-right);
        return cost[node-1]+max(left,right);
    }
public:
    int minIncrements(int n, vector<int>& cost) {
        inc(1,cost,n);
        return sum;
    }
};