struct Node{
    Node* links[2];
    bool containskey(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int x){
        Node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(x>>i)&1;
            if(!curr->containskey(bit)){
                curr->put(bit,new Node());
            }
            curr=curr->get(bit);
        }
    }
    int findmax(int x){
        Node* curr=root;
        int maxnum=0;
        for(int i=31;i>=0;i--){
            int bit=(x>>i)&1;
            if(curr->containskey(!bit)){
                maxnum=maxnum|(1<<i);
                curr=curr->get(!bit);
            }
            else{
                curr=curr->get(bit);
            }
        }
        return maxnum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<queries.size();i++){
            v.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(v.begin(),v.end());
        sort(nums.begin(),nums.end());
        Trie trie;
        vector<int>ans(queries.size(),0);
        int j=0;
        for(int i=0;i<v.size();i++){
            int ele=v[i].first;
            int xowala=v[i].second.first;
            int idx=v[i].second.second;
            while(j<nums.size()&&ele>=nums[j]){
                trie.insert(nums[j]);
                j++;
            }
            if(j==0){
                ans[idx]=-1;
            }
            else{
                ans[idx]=trie.findmax(xowala);
            }
        }
        return ans;
    }
};