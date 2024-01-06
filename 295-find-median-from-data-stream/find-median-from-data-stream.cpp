class MedianFinder {
    priority_queue<int>maxpq;
	priority_queue<int,vector<int>,greater<int>>minpq;
    int n;
public:
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
        int x=maxpq.size();
		int y=minpq.size();
		if(x==y){
			if(x==0){
				maxpq.push(num);
			}
            else{
                if(minpq.size()==0){
                    if(num>maxpq.top()){
                        minpq.push(num);
                    }
                    else{
                        minpq.push(maxpq.top());
                        maxpq.pop();
                        maxpq.push(num);
                    }
                }
                else{
                    if(minpq.top()<=num){
                        maxpq.push(minpq.top());
                        minpq.pop();
                        minpq.push(num);
                    }
                    else{
                        maxpq.push(num);
                    }
                }
            }
		}
		else if(x>y){
			if(maxpq.top()>=num){
				minpq.push(maxpq.top());
				maxpq.pop();
				maxpq.push(num);
			}
			else{
				minpq.push(num);
			}
		}
        n++;
    }
    
    double findMedian() {
        if(maxpq.size()>minpq.size()){
            return double(maxpq.top());
        }
        double first=double(minpq.top());
        double sec=double(maxpq.top());
        return (first+sec)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */