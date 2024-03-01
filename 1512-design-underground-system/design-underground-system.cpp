class UndergroundSystem {
    map<int,pair<string,int>>mp;
    map<pair<string,string>,pair<double,int>>mp1;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string sta, int t) {
        // if(mp.find(id)!=mp.end()){
        //     mp.erase(id);
        // }
        mp[id]={sta,t};
    }
    
    void checkOut(int id, string sta, int t) {
        string s=mp[id].first;
        int dur=t-mp[id].second;
        mp.erase(id);
        mp1[{s,sta}].first+=dur;
        mp1[{s,sta}].second+=1;
    }
    
    double getAverageTime(string start, string end) {
        return (double)mp1[{start,end}].first/mp1[{start,end}].second;
    }
};