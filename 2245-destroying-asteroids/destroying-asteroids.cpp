class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        long long x=mass;
        for(int i=0;i<ast.size();i++){
            if(x>=ast[i]){
                x+=(long long)ast[i];
            }
            else return 0;
        }
        return 1;
    }
};