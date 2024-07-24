class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>vec(26,0);
        for(int i=0;i<word.size();i++){
            vec[word[i]-'a']++;
        }
        int mini = word.size();
        for(int i=0;i<26;i++){
            int dele = 0;
            for(int j=0;j<26;j++){
                if(j==i)continue;
                if(vec[j]<vec[i]){
                    dele += vec[j];
                }
                else if(vec[j]-vec[i]>k){
                    dele += (vec[j]-vec[i]-k);
                }
            }
            mini = min(mini,dele);
        }
        return mini;
    }
};