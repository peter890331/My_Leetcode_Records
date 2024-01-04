class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> check;
        for (int i=0; i<nums.size(); i++){
            check[nums[i]] ++;
        }
        for (const pair<int, int>& j: check){
            // cout<<j.first<<": "<<j.second<<endl;
            // if (j.second % 3 == 0) result += j.second / 3;
            // else if (j.second % 2 == 0) result += j.second / 2;
            // else return -1;
            if (j.second == 1) return -1;
            result += j.second/3;
            if (j.second % 3 != 0) result++;
        }
        return result;
    }
};

// Reference from MarkSPhilip31's solution.