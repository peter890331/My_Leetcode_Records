class Solution {
public:
    static bool mycompare(pair<int, int> a, pair<int, int> b) {
    // compare function，用於sort的第三個變數，修改排列順序
    return a.second > b.second; // 降序排列，依照pairs的第二個數值
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        for (const int& i: nums){
            mp[i] ++;
        }
    vector <pair<int, int>> v_mp (mp.begin(), mp.end()); // 將map轉換為vector，vector包含所有pairs
    vector <int> results;
    sort(v_mp.begin(), v_mp.end(), mycompare); // sort，依照pairs的第二個數值
    for (int i=0; i<k; i++){
        results.push_back(v_mp[i].first);
    }
    return results;
    }
};
