class FoodRatings {
    unordered_map<string,set<pair<int,string>>> cui;
    unordered_map<string,int> food;
    unordered_map<string,string>mp; 
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            food[foods[i]]=ratings[i];
            cui[cuisines[i]].insert({-ratings[i],foods[i]});
            mp[foods[i]]=cuisines[i];
        }
    }

    void changeRating(string foo, int newRating) {
        string c=mp[foo];
        int old=food[foo];
        food[foo]=newRating;
        cui[c].erase({-old,foo});
        cui[c].insert({-newRating,foo});
    }
    
    string highestRated(string cuisine) {
        return cui[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */