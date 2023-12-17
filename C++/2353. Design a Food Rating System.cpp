class FoodRatings {
public:
    // 用map的原因是方便找highestRated。
    map<string, pair<string, int>> foods_cuisines_ratings;
    map<string, map<int, set<string>>> cuisines_ratings_foods; // 同一類中，可能有多個同分，所以同分的食物用set。

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foods_cuisines_ratings[foods[i]] = {cuisines[i], ratings[i]};
            cuisines_ratings_foods[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto food_info = foods_cuisines_ratings.find(food); // .find()輸出是迭代器，所以下兩行要用指針。
        auto food_cuisines = food_info->second.first;       // 迭代器指向pair，再對應pair中的string。
        auto food_oldRating = food_info->second.second;     // 迭代器指向pair，再對應pair中的int。
        foods_cuisines_ratings[food].second = newRating;    // foods_cuisines_ratings[food]就已經是指其pair，所以後面用.second就對應pair中的int。

        cuisines_ratings_foods[food_cuisines][food_oldRating].erase(food); // 用erase清除set中的食物。
        if (cuisines_ratings_foods[food_cuisines][food_oldRating].empty()) // 若food_oldRating剛好只有剛剛被erase的食物，
            cuisines_ratings_foods[food_cuisines].erase(food_oldRating);   // 就erase這整個food_oldRating。避免map中的排序出錯。
        cuisines_ratings_foods[food_cuisines][newRating].insert(food);     // insert newRating的set中的食物。
    }
    
    string highestRated(string cuisine) {
        return *cuisines_ratings_foods[cuisine].rbegin()->second.begin(); 
        // 輸出以map排序好的，種類中最大分數的最小字串。
        // .rbegin()是輸出最後位置的迭代指針，所以也要用指標。
        // 最後的.begin()是輸出set中的第一個迭代指針，所以最前面要用*解引用。
    }
};

// Reference from abhay53's solution.

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */