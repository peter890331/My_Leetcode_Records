class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy_price = INT_MAX;
        // 如果是int型，可以用INT_MAX表示正無窮，INT_MIN表示負無窮，需要包含標頭檔案limits.h。
        int max_profit = 0;
        for (int i=0; i<n; i++){
            buy_price = min(buy_price, prices[i]);
            max_profit = max(max_profit, prices[i] - buy_price);
        }
        return max_profit;
    }
};

// Refer to its_vishal_7575's solution.