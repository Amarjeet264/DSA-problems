#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i = 1;
        int st = 1;
        while (i < n) {
            if (arr[i] >= arr[i - 1]) {
                st++;
            } else {
                break;
            }
            i++;
        }
        i--;
        int ans = st;
        int j = n - 2;
        int en = 1;
        while (j >= i) {
            if (arr[j] <= arr[j + 1]) {
                en++;
            } else {
                break;
            }
            j--;
        }
        ans = max(ans,en);
        j++;
        // cout<<i<<" "<<j<<endl;
        while(i>=0){
            int idx = lower_bound(arr.begin()+j,arr.end(),arr[i])-arr.begin();
            // cout<<idx<<endl;
            ans = max(ans,i+n-idx+1);
            i--;
        }
        return n-ans<=0?0:n-ans;
    }
};
