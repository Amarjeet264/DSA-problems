struct Node{
    Node* Links[26];
    bool isterminal=false;

    bool containsKey(char ch){
        return Links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        Links[ch-'a']=node;
    }
    void setend(){
        isterminal=true;
    }
    bool isend(){
        return isterminal;
    }
    Node* get(char ch){
        return Links[ch-'a'];
    }
};
class Trie{
    private:Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insertandcheck(string word,string &ans){
        string x="";
        Node* curr=root;
        bool mila=true;
        for(int i=0;i<word.length();i++){
            if(mila&&curr->containsKey(word[i])){
                curr=curr->get(word[i]);
                x+=word[i];
            }
            else{  
                break;
            }
        }
        if(x.length()<ans.length()){
            ans= x;
        }
    }
    void insert(string word) {
        Node* curr=root;
        for(int i=0;i<word.length();i++){
            if(!curr->containsKey(word[i])){
                curr->put(word[i],new Node());
            }
            curr=curr->get(word[i]);
        }
        // curr->setEnd();
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        sort(a.begin(), a.end(), [](string x, string y){return x.length() < y.length();});
        Trie obj;
        int maxi=0;
        string ans=a[0];
        obj.insert(a[0]);
        int n=a.size();
        for(int i=0;i<n;i++){
            obj.insertandcheck(a[i],ans);
        }
        return ans;
    }
};