class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        vector<unordered_map<long long, int>> dp(n);
        // dp[i][diff] 表示以索引 i 结尾的等差子序列的数量，其中公差（等差差值）为 diff。

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // 外层循环遍历数组中的每个元素，内层循环遍历当前元素之前的每个元素，以构建以当前元素为结尾的等差子序列。
                long long diff = (long long)nums[i] - nums[j];
                // 将 diff 声明为 long long 类型。使用 long long 类型可以容纳更大范围的整数，避免在相减操作时发生溢出。

                if (diff < INT_MIN || diff > INT_MAX)
                    continue;
                    // 如果 diff 的值小于 INT_MIN 或大于 INT_MAX，则 continue，结束当前迭代并开始下一次迭代。

                int count = dp[j].count(diff) ? dp[j][diff] : 0;
                // 在C++中，dp[j].count(diff) 是unordered_map的成员函数，用于检查在dp[j]这个unordered_map中是否存在以diff为键的元素。
                // 返回值是一个整数，表示以diff为键的元素的数量（0或1，因为unordered_map中每个键只能对应一个值）。

                result += count;
                
                dp[i][diff] += count + 1;
                // 在索引 i 处，以公差 diff 结尾的等差子序列数量增加 count + 1。
                // 因为在索引 i 处扩展了一个元素，使得原有的以索引 j 结尾、以公差 diff 的等差子序列增加了一个新的可能性。
            }
        }
        return result;
    }
};

// Recode_-1's solution.