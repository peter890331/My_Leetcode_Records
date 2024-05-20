class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        // Iterate through all possible subsets
        for (int i = 0; i < (1 << n); i++) {
            int subsetXor = 0;
            for (int j = 0; j < n; j++) {
                // Check if the j-th element is in the i-th subset
                if (i & (1 << j)) {
                    subsetXor ^= nums[j];
                }
            }
            totalSum += subsetXor;
        }
        return totalSum;
    }
};

// Mohammed_Raziullah_Ansari's solution.
/*

假設 nums = [5, 1, 6]，長度 n = 3。程式會遍歷所有可能的子集，這些子集可以用 0 到 2^n - 1 (即 0 到 7) 之間的數字來表示。每個數字 i 的二進制表示對應於一個子集。

外層循環：遍歷所有子集
外層循環從 0 到 7（包括）逐個檢查：
for (int i = 0; i < (1 << n); i++) {

當 i = 0，二進制 000 對應空集 []。
當 i = 1，二進制 001 對應子集 [5]。
當 i = 2，二進制 010 對應子集 [1]。
當 i = 3，二進制 011 對應子集 [5, 1]。
當 i = 4，二進制 100 對應子集 [6]。
當 i = 5，二進制 101 對應子集 [5, 6]。
當 i = 6，二進制 110 對應子集 [1, 6]。
當 i = 7，二進制 111 對應子集 [5, 1, 6]。

    內層循環：檢查子集中的元素
    內層循環檢查每個元素是否在當前子集中：
    for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
            subsetXor ^= nums[j];
        }
    }

    例子解析
    當 i = 5 (二進制 101)：

    初始化 subsetXor = 0。
    內層循環 j 從 0 到 2（包括）逐一檢查：

    j = 0：檢查 i & (1 << 0)：
    1 << 0 結果是 001。
    i & 001 結果是 101 & 001 = 001，非零，所以 subsetXor ^= nums[0] 即 subsetXor ^= 5，此時 subsetXor = 5。

    j = 1：檢查 i & (1 << 1)：
    1 << 1 結果是 010。
    i & 010 結果是 101 & 010 = 000，為零，所以不執行 XOR 操作，subsetXor 保持不變。

    j = 2：檢查 i & (1 << 2)：
    1 << 2 結果是 100。
    i & 100 結果是 101 & 100 = 100，非零，所以 subsetXor ^= nums[2] 即 subsetXor ^= 6，此時 subsetXor = 5 ^ 6 = 3。

    最後，totalSum += subsetXor 即 totalSum += 3。

完整流程解析
當 i = 0：子集 []，subsetXor = 0，totalSum += 0。
當 i = 1：子集 [5]，subsetXor = 5，totalSum += 5。
當 i = 2：子集 [1]，subsetXor = 1，totalSum += 1。
當 i = 3：子集 [5, 1]，subsetXor = 4，totalSum += 4。
當 i = 4：子集 [6]，subsetXor = 6，totalSum += 6。
當 i = 5：子集 [5, 6]，subsetXor = 3，totalSum += 3。
當 i = 6：子集 [1, 6]，subsetXor = 7，totalSum += 7。
當 i = 7：子集 [5, 1, 6]，subsetXor = 2，totalSum += 2。

總和計算
totalSum = 0 + 5 + 1 + 4 + 6 + 3 + 7 + 2 = 28
所以，返回的總和是 28。

*/