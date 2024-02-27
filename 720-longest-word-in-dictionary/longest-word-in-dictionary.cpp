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
    bool cantake(string word) {
        Node* curr=root;
        int cnt=0;
        for(int i=0;i<word.length();i++){
            if(!curr->containskey(word[i])){
                // cout<<i<<" ";
                // cnt++;
                if(i==word.length()-1){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            curr=curr->get(word[i]);
        }
        // if(cnt==0)return 0;
        return 1;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        int maxi=INT_MIN;
        Trie trie;
        string ans="";
        for(int i=0;i<words.size();i++){
            if(trie.cantake(words[i])){
                // cout<<i<<" ";
                if(ans.size()<words[i].length()){
                    // cout<<"ret";
                    // maxi=words[i].length();
                    ans=words[i];
                }
                trie.insert(words[i]);
            }
        }
        return ans;
    }
};