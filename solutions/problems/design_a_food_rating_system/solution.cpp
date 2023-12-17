class FoodRatings {
public:
    map<string,set<pair<int,string>>> mp; // map: cuisine -> pair<-rating,food name>
    map<string,pair<string,int>> rates; // map: food name -> pair<food, rating>


    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            if (mp.find(cuisines[i]) == mp.end()) {
                set<pair<int,string>> st;
                mp[cuisines[i]] = st;
            }
            mp[cuisines[i]].insert(make_pair(-ratings[i],foods[i]));
            rates[foods[i]] = make_pair(cuisines[i],-ratings[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        pair<string,int> curData = rates[food]; //pair<food, rating>
        mp[curData.first].erase(make_pair(curData.second,food));
        rates[food].second = -newRating;
        mp[curData.first].insert(make_pair(-newRating,food));
    }
    
    string highestRated(string cuisine) {
        return (*(mp[cuisine].begin())).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */