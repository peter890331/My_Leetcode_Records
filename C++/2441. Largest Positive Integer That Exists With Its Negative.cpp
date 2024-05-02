class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=nums.size()-1; i>=0; i--){
            if (find(nums.begin(), nums.end(), -nums[i]) != nums.end())
                return nums[i];
        }
        return -1;
    }
};


// sort, https://shengyu7697.github.io/std-sort/.
// find, https://shengyu7697.github.io/std-find/.