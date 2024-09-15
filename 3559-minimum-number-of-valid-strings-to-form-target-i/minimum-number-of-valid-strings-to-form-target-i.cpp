struct Node{
    Node* links[26];
    public:
    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    void put(char ch,Node* naya){
        links[ch-'a'] = naya;
    }
    Node* getEle(char ch){
        return links[ch-'a'];
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string s){
        Node* curr = root;
        for(int i = 0;i<s.size();i++){
            if(!curr->containsKey(s[i])){
                curr->put(s[i],new Node());
            }
            curr = curr->getEle(s[i]);
        }
    }
    int helper(int idx,string &target,vector<int>&dp){
        if(idx>=target.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int mini = 1e9;
        Node* curr = root;
        int i = idx;
        while(i<target.size()){
            if(curr->containsKey(target[i])){
                curr = curr->getEle(target[i]);
                // char ch = target[i];
                mini = min(mini,1+helper(i+1,target,dp));
                // curr = curr->getEle(ch);
                i++;
            }
            else{
                break;
            }
        }
        return dp[idx] = mini;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie tt;
        for(int i=0;i<words.size();i++){
            tt.insert(words[i]);
        }
        vector<int>dp(target.size(),-1);
        int x = tt.helper(0,target,dp);
        if(x>=1e9)return -1;
        return x;
    }
};