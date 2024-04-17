class LUPrefix {
    vector<int>myVector;
        int idx=0;
public:
    LUPrefix(int n) {
        myVector.resize(n,0);
    }
    
    void upload(int video) {
        myVector[video-1]=1;
    }
    
    int longest() {
        for(int i=idx;i<myVector.size();i++){
            if(myVector[i]==0){
                return idx;
            }
            else{
                idx++;
            }
        }
        return idx;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */