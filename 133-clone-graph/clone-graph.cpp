/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    void dfs(Node* copy,Node* curr,map<int,Node*>&mp){
        mp[curr->val]=copy;
        for(auto nayacurr:curr->neighbors){
            if(mp[nayacurr->val]==NULL){
                Node* naya=new Node(nayacurr->val);
                (copy->neighbors).push_back(naya);
                dfs(naya,nayacurr,mp);
            }
            else{
                (copy->neighbors).push_back(mp[nayacurr->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
       if(!node)return nullptr;
       map<int,Node*>mp;
       Node* copy= new Node(node->val);
       mp[node->val]=copy;
       for(auto curr:node->neighbors){
           if(mp[curr->val]==NULL){
               Node* nayicopy=new Node(curr->val);
               (copy->neighbors).push_back(nayicopy);
               dfs(nayicopy,curr,mp);
           }
           else{
               (copy->neighbors).push_back(mp[curr->val]);
           }
       }
       return copy;
    }
};