class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int num1 = 0;
        int num2 = 0;
        for (int n: nums){
            if (n >= num1){
                num2 = num1;
                num1 = n;
            }
            else if (n > num2){
                num2 = n;
            }
        }
        return (num1-1)*(num2-1);
    }
};

// 用for只要O(n)，用sort要O(nlogn)。