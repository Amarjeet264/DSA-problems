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
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        Node * naya = new Node();
        naya->val = node->val;
        unordered_map<Node*,Node*>mp;
        mp[node] = naya;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* root = q.front();
            q.pop();
            vector<Node*>neigh = root->neighbors;
            int n = neigh.size();
            for(int i=0;i<n;i++){
                if(mp[neigh[i]] == nullptr){
                    naya = new Node();
                    naya->val = neigh[i]->val;
                    mp[neigh[i]] = naya;
                    q.push(neigh[i]);
                }
                mp[root]->neighbors.push_back(mp[neigh[i]]);
            }
        }
        return mp[node];
    }
};