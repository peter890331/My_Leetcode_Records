class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> result_set;
        sort(nums.begin(), nums.end());
        // for (const int& i: nums) cout << i << ',';
        for (int i=0; i<nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;
            while (j<k){
                if (nums[i]+nums[j]+nums[k]==0){
                    result_set.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (nums[i]+nums[j]+nums[k]<0) j++;
                else k--;
            }
        }
        for (const auto& s: result_set) result.push_back(s);
        return result;
    }
};

// set 是一個關聯式容器，set 容器裡面的元素是唯一的，具有不重複的特性，而且是有排序的容器，set 容器裡面元素的值是不可修改，但 set 容器可以插入或刪除元素。https://shengyu7697.github.io/std-set/

// Reference from singhabhinash's solution.