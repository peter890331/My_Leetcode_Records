class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len_nums = nums.size();

        unordered_map<int, int> mp;
        for (int i=0; i<len_nums; i++){
            mp[nums[i]] = i;        // [數字, index]
        }
        
        for (int i=0; i<len_nums; i++){
            int t = target-nums[i];
            if (mp.find(t) != mp.end() && mp[t] != i){
                return {i, mp[t]};
            }
        }
        return {};
    }
};