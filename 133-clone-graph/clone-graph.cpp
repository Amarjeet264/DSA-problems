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
    void dfs(Node* curr,Node* copy,map<int,Node*>&mp){
        mp[copy->val]=copy;
        for(auto ele:curr->neighbors){
            if(mp[ele->val]==NULL){
                Node* naya=new Node(ele->val);
                (copy->neighbors).push_back(naya);
                dfs(ele,naya,mp);
            }
            else{
                (copy->neighbors).push_back(mp[ele->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)return node;
        map<int,Node*>mp;
        Node* copy=new Node(node->val);
        mp[node->val]=copy;
        for(auto curr:node->neighbors){
            if(mp[curr->val]==NULL){
                Node* naya=new Node(curr->val);
                (copy->neighbors).push_back(naya);
                dfs(curr,naya,mp);
            }
            else{
                (copy->neighbors).push_back(mp[curr->val]);
            }
        }
        return copy;
    }
};