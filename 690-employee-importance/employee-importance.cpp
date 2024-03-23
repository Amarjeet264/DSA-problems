/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    unordered_set<int>x;
    void call(map<int,vector<int>>&mp1,int id){
        vector<int>vec=mp1[id];
        for(int i=0;i<vec.size();i++){
            x.insert(vec[i]);
            call(mp1,vec[i]);
        }
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,int>mp;
        map<int,vector<int>>mp1;
        int sum=0;
        x.insert(id);
        for(int i=0;i<employees.size();i++){
            mp[employees[i]->id]=employees[i]->importance;
            mp1[employees[i]->id]=employees[i]->subordinates;
        }
        call(mp1,id);
        for(auto it:x){
            sum+=mp[it];
        }
        return sum;
    }
};