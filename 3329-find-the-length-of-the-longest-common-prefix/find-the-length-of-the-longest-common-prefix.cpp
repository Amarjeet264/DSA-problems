struct Node{
    Node* links[26];
    bool isterminal=false;
    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setend(){
        isterminal=true;
    }
    bool isend(){
        return isterminal;
    }
};
class Trie {
    private:Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* curr=root;
        for(int i=0;i<word.length();i++){
            if(!curr->containskey(word[i])){
                curr->put(word[i],new Node());
            }
            curr=curr->get(word[i]);
        }
        curr->setend();
    }
    int cntlength(string word) {
        int cnt=0;
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(curr->containskey(word[i])){
                cnt++;
            }
            else{
                break;
            }
            curr=curr->get(word[i]);
        }
        return cnt;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        vector<string>num2;
        unordered_map<char,char>mp;
        mp['0']='a';
        mp['1']='b';
        mp['2']='c';
        mp['3']='d';
        mp['4']='e';
        mp['5']='f';
        mp['6']='g';
        mp['7']='h';
        mp['8']='i';
        mp['9']='j';
        for(int i=0;i<arr1.size();i++){
            string s=to_string(arr1[i]);
            for(int j=0;j<s.size();j++){
                s[j]=mp[s[j]];
            }
            // cout<<s<<" ";
            trie.insert(s);
        }
        for(int i=0;i<arr2.size();i++){
            string s=to_string(arr2[i]);
            for(int j=0;j<s.size();j++){
                s[j]=mp[s[j]];
            }
            // cout<<s<<" ";
            num2.push_back(s);
        }
        int maxi=0;
        for(int i=0;i<num2.size();i++){
            maxi=max(maxi,trie.cntlength(num2[i]));
        }
        return maxi;
    }
};