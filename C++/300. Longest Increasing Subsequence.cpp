class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        vector<int> dp(n, 1);
        // cout<<"init:  ";
        // print(dp);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                // cout<<nums[i]<<','<<nums[j]<<":  ";
                // print(dp);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

private:
    void print(vector<int>& nums){
        for (int i=0; i<nums.size(); i++) cout<<nums[i]<<',';
        cout<<endl;
    }
};

// Reference from MrAke's solution.