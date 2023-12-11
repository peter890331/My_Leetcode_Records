class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map <int, int> count;
        float quarter = static_cast<float>(arr.size())/4;
        for (int num: arr) count[num]++;
        for (const auto& pair: count){
            if (pair.second > quarter) return pair.first;
        }
        return -1;
    }
};