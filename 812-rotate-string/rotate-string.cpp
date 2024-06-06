class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return 0;
        }
        s+=s;
        if(s.find(goal) != std::string::npos)return 1;
        return 0;
    }
};