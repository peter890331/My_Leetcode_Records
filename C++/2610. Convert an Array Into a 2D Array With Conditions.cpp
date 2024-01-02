class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result(1, vector<int>(1, nums[0]));
        // print(result);
        for (int i=1; i<nums.size(); i++){
            bool flag = false;
            for (int j=0; j<result.size(); j++){
                if (find(result[j].begin(), result[j].end(), nums[i]) == result[j].end()){
                    result[j].push_back(nums[i]);
                    flag = true;
                    break;
                }
            }
            if (flag == false){
                    result.push_back(vector<int>(1, nums[i]));
            }
            // print(result);
        }
        return result;
    }
    void print(vector<vector<int>> result){
        for (int i=0; i<result.size(); i++){
            for (int j=0; j<result[i].size(); j++){
                cout<<result[i][j]<<',';
            }
            cout<<endl;
        }
    }
};