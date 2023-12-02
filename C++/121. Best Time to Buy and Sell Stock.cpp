class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy_price = INT_MAX;
        // �p�G�Oint���A�i�H��INT_MAX��ܥ��L�a�AINT_MIN��ܭt�L�a�A�ݭn�]�t���Y�ɮ�limits.h�C
        int max_profit = 0;
        for (int i=0; i<n; i++){
            buy_price = min(buy_price, prices[i]);
            max_profit = max(max_profit, prices[i] - buy_price);
        }
        return max_profit;
    }
};

// Refer to its_vishal_7575's solution.