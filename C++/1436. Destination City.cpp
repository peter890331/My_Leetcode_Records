class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map <string, int> city0;
        for (const auto& city: paths){
            city0[city[0]] ++;
        }
        for (const auto& city: paths){
            if (city0.find(city[1])==city0.end()) return city[1];
        }
        return "";
    }
};