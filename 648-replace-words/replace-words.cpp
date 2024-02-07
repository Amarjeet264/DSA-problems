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
    string search(string word) {
        Node* curr=root;
        string s="";
        for(int i=0;i<word.length();i++){
            if(!curr->containskey(word[i])){
                return "@";
            }
            s+=word[i];
            curr=curr->get(word[i]);
            if(curr->isend()){
                return s;
            }
        }
        return "@";
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie trie;
        for(int i=0;i<dict.size();i++){
            trie.insert(dict[i]);
        }
        int i=0;
        string s="";
        string ans="";
        while(i<sentence.size()){
            s+=sentence[i];
            i++;
            if(sentence[i]==' '){
                string x=trie.search(s);
                if(trie.search(s)!="@"){
                    ans+=x;
                }
                else{
                    ans+=s;
                }
                ans+=' ';
                i++;
                s="";
            }
        }
        if(s.size()>0){
            // ans+=' ';
            string x=trie.search(s);
            if(trie.search(s)!="@"){
                ans+=x;
            }
            else{
                ans+=s;
            }
            i++;
        }
        return ans;
    }
};