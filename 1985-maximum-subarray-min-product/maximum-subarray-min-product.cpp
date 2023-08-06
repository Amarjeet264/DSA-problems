class Solution {
public:
    int maxSumMinProduct(vector<int>&A) {
        long long mod = 1e9+7, N = A.size(), ans = 0;
        vector<long long>sum(N);
        sum[0]=A[0];
        for (int i =1; i < N;i++){
            sum[i]=sum[i-1] + A[i];
        }

        vector<int> prev(N, -1), next(N, -1); 
        
        stack<int> s;
       
        for (int i = 0; i < N;i++) { 
            while (s.size() && A[s.top()] >= A[i]){
                s.pop();
            }
            if (!s.empty()) prev[i] = s.top();
            s.push(i);
        }
        
        while(!s.empty()){
            s.pop();
        }


        for (int i = N - 1; i >= 0;i--) {
            while (!s.empty() && A[s.top()] >= A[i]){
               s.pop();
            }
            if (!s.empty()) next[i] = s.top();
            s.push(i);
        }

        for (int i = 0; i < N; ++i) {
            cout<<prev[i]<<" "<<next[i]<<" ";
        }

        for (int i = 0; i < N; ++i) {

            long long s = next[i];
            if(s==-1){
                s=sum.back();
            }
            else s= sum[next[i]-1];
            if (prev[i] != -1) {
                s -= sum[prev[i]];
            }
            ans = max(ans, (long long) A[i] * s);
        }
        return ans % mod;
    }
};