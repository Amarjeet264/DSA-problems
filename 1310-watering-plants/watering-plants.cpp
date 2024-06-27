class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        if(plants.size()==0){
            return 0;
        }
        int steps=1;
        int cap=capacity;
        for(int i=0;i<plants.size();i++){
            capacity-=plants[i];
            // steps++;
            if(i+1<plants.size()&&capacity<plants[i+1]){
                capacity = cap;
                steps+=(2*(i+1))+1;
            }
            else{
                if(i+1<plants.size())steps++;
            }
        }
        return steps;
    }
};