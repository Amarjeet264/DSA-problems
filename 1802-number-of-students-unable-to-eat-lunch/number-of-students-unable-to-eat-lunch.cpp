class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& sand) {
        queue<int>q;
        int i=0;
        int j=0;
        while(i<stu.size()&&j<sand.size()){
            if(stu[i]==sand[j]){
                i++;
                j++;
            }
            else{
                q.push(stu[i]);
                i++;
            }
        }
        while(!q.empty()){
            int prev=q.size();
            for(int i=0;i<prev;i++){
                int fr=q.front();
                q.pop();
                if(fr==sand[j]){
                    j++;
                }
                else{
                    q.push(fr);
                }
            }
            if(q.size()==prev){
                break;
            }
        }
        return q.size();
    }
};