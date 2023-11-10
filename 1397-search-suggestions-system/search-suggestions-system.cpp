// class Trie{
//     Node* root;
//     public:
//     root=new Node();
//     void insert(string s){
//         Node* curr=root;
//         for(int i=0;i<s.length();i++){
//             if(!curr->containskey(s[i])){
//                 curr->put(s[i],new Node());
//             }
//             curr=curr->get(s[i]);
//         }
//     }
//     void find(string s,vector<string>&dup,int i){
        
//     }
// };
struct Node{
    Node* links[26];
    vector<string>all;
    bool flag=false;
    // public:
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
        flag=true;
    }
};

class Solution {
public:
    void insert(Node* curr,string s,stack<Node*>&st){
        st.push(curr);
        for(int i=0;i<s.length();i++){
            if(!curr->containskey(s[i])){
                curr->put(s[i],new Node());
            }
            curr=curr->get(s[i]);
            st.push(curr);
        }
        curr->setend();
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        vector<vector<string>>ans(search.size());
        sort(products.begin(),products.end());
        Node* curr=new Node();
        for(auto word:products){
            stack<Node*>st;
            insert(curr,word,st);
            while(!st.empty()){
                Node*temp=st.top();
                st.pop();
                if(temp->all.size()<3){
                    temp->all.push_back(word);
                }
            }
        }
        // curr=new Node();
        for(int i=0;i<search.size();i++){
            if(!curr->containskey(search[i])){
                return ans;
            }
            curr=curr->get(search[i]);
            ans[i]=curr->all;
        }
        return ans;
    }
};