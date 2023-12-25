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
    void clone(Node* root1,unordered_map<int,Node*>&mp,Node* curr){
        // Node* root1=new Node(curr->val);
        for(int i=0;i<curr->neighbors.size();i++){
            Node* curr1=curr->neighbors[i];
            if(mp[curr1->val]==nullptr){
                Node* nayacurr1=new Node(curr1->val);
                mp[curr1->val]=nayacurr1;
                root1->neighbors.push_back(nayacurr1);
                clone(nayacurr1,mp,curr1);
            }
            else{
                 root1->neighbors.push_back(mp[curr1->val]);
            } 
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        Node* root=new Node(node->val);
        unordered_map<int,Node*>mp;
        mp[root->val]=root;
        for(int i=0;i<node->neighbors.size();i++){
            Node* curr=node->neighbors[i];
            if(mp[curr->val]==0){
                Node* nayacurr=new Node(curr->val);
                mp[curr->val]=nayacurr;
                root->neighbors.push_back(nayacurr);
                clone(nayacurr,mp,curr);
            }
            else{
                root->neighbors.push_back(mp[curr->val]);
            }
        }
        return root;
    }
};