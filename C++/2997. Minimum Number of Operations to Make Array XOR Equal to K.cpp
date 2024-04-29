class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int temp = 0;                               // 先設一個 000...0。
        for (auto num: nums){
            temp ^= num;                            // 計算 num1 ^ num2 ^ ... numn = x。
        }
        temp ^= k;                                  // x ^ k == 0 等價於 x == k，檢查 x ^ k 有幾個位元是 1 即可得知需要翻轉幾個位元之後會變成 000...0。

        int ans_count = 0;
        // cout<< "temp: " << temp << endl;
        while(temp){                                // 使用 while(temp) 循環，當 temp 非零時，表示還有位元需要檢查。
            if (temp % 2) ans_count++;              // 對 temp 求餘數，判斷最低位是否為 1，如果是，則 ans_count++。
            temp /= 2;                              // 將 temp 除以 2，這實際上是將 temp 的二進制表示向右移動一位，並且在這個過程中，原本最低位的數字被移除了。
            // cout<< "temp: " << temp << endl;
        }
        return ans_count;
    }
};

// 假設 num1 ^ num2 ^ ... numn = x，我們希望 x == k 等價於 x ^ k == 0，所以我們把 nums 的所有元素和 k 做 xor 然後看看翻轉幾個 1 可以令他為 0 即可。
// Reference from 批踢踢實業坊, [閒聊] 每日leetcode, Mon Apr 29 09:35:55 2024, https://www.ptt.cc/bbs/Marginalman/M.1714354557.A.F45.html.
// Reference from 2997. Minimum Number of Operations to Make Array XOR Equal to K - Day 29/30 Leetcode April Challenge, https://youtu.be/oCmdolZa7oE.
// Reference from leetcode daily challenge - 2997. Minimum Number of Operations to Make Array XOR Equal to K, https://youtu.be/M7VSNDVVDoA.