struct Node{
    Node* links[27];
    bool isterminal=false;
    bool containskey(char ch){
        if(ch=='/')return links[26]!=nullptr;
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        if(ch=='/'){
            links[26]=node;
        }
        else links[ch-'a']=node;
    }
    Node* get(char ch){
        if(ch=='/'){
            return links[26];
        }
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
    bool search(string word) {
        Node *temp = root;
        int i = 0;
      // we go on till we reacha null node
        while (temp)
        {
            
            if (!temp->containskey(word[i])&&word[i]!='/')
            {//when  the trie doesnot contain the word[i] and the word[i]!='/' it means the directory is not matching i.e the prefix didnot match 
          // when  the trie doesnot contain the word[i]  if however word[i]=='/'  then no issue ie some directory has been covered hence   some prefix of word exists in trie.
                return false;
            }
            temp = temp->get(word[i]);

            i++;
        } 

        return true;
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        Trie trie;
        vector<string>ans;
        trie.insert(folder[0]);
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            // cout<<folder[i]<<" ";
            if(!trie.search(folder[i])){
                ans.push_back(folder[i]);
                trie.insert(folder[i]);
            }
        }
        return ans;
    }
};