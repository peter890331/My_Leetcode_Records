class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int n = happiness.size();
        long long ans = 0;
        int temp_k = k;
        int m = 0;
        for (int i=n-1; i>=0; i--){
            if (temp_k > 0){
                ans += max(happiness[i] - m, 0);
                m++;
                temp_k--;
            }
        }
        return ans;
    }
};