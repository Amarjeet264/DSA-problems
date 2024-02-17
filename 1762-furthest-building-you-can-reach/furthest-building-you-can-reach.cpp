class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int cnt=0;
        int i=0;
        while(i<heights.size()-1){
            if(heights[i+1]<=heights[i]){
                cnt++;
                i++;
                continue;
            }
            else{
                if(ladders>0){
                    pq.push(heights[i+1]-heights[i]);
                    cnt++;
                    ladders--;
                }
                else{
                    if(!pq.empty()){
                        if(heights[i+1]-heights[i]<=pq.top()&&heights[i+1]-heights[i]<=bricks){
                            bricks-=(heights[i+1]-heights[i]);
                            cnt++;
                        }
                        else{
                            if(bricks>=pq.top()){
                                bricks-=pq.top();
                                cnt++;
                                pq.push(heights[i+1]-heights[i]);
                                pq.pop();
                            }
                            else{
                                return cnt;
                            }
                        }
                    }
                    else{
                        if(heights[i+1]-heights[i]<=bricks){
                            bricks-=(heights[i+1]-heights[i]);
                            cnt++;
                        }
                        else{
                            return cnt;
                        }
                    }
                }
            }
            i++;
            if(i==heights.size()-1){
                return i;
            }
        }
        return cnt;
    }
};