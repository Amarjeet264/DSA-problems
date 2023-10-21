struct Node{
    Node* links[26];
    bool isterminal=false;
    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* getele(char ch){
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
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containskey(word[i])){
                curr->put(word[i],new Node());
            }
            curr=curr->getele(word[i]);
        }
        curr->setend();
    }
    
    bool search(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containskey(word[i])){
                return false;
            }
            curr=curr->getele(word[i]);
        }
        return curr->isend();
    }
    
    bool startsWith(string prefix) {
        Node* curr=root;
        for(int i=0;i<prefix.size();i++){
            if(!curr->containskey(prefix[i])){
                return false;
            }
            curr=curr->getele(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */