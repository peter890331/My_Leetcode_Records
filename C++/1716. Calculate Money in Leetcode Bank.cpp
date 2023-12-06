class Solution {
public:
    int totalMoney(int n) {
        int n_7 = n / 7;
        int n_7_ = n % 7;
        int result = n_7*28 + 0+7*(n_7*(n_7-1)/2) + n_7_*((1+(n_7)*1)+((1+(n_7)*1)+(n_7_-1)*1))/2;
        return (result);
    }
};

// 等差級數:
// a_n = a_1+(n-1)*d
// S_n = a_n+d*(n*(n-1)/2) = n*(a_1+a_n)/2