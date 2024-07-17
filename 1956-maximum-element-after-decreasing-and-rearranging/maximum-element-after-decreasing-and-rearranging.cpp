class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(n+1, 0);
        for(int x : arr) {
            count[min(x, n)]++;
        }
        
        int maxEl = 1;
          for (int i = 1; i <= n; ++i) {
            int freq = count[i];
            maxEl = min(maxEl + freq, i); 
        }

        // return maxEl;
        return maxEl;
    }
};