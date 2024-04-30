class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();                    // 取得字串的長度。
        int state = 0;                          // 初始化狀態為 0，表示所有字元出現的次數都是偶數次。
        vector<int> count(1<<10);               // 1<<10 是位元操作符，代表將數字 1 向左移動 10 位，相當於 2 的 10 次方，也就是 1024。用來記錄各種狀態出現的次數。
        count[0] += 1;                          // 什麼字符都沒有，所有字符出現 0 次。

        long long ans = 0;
        for (int i=0; i<n; i++){
            int k = word[i] - 'a';              // 取得字元對應的索引值。
            state = state ^ (1<<k);             // state[i]，更新狀態，將第 k 位的二進制翻轉一次。

            ans += count[state];                // 全是偶數的狀態，找 state 相同，找 state[i] = state[j]。

            for (int k=0; k<10; k++){           // 遍歷所有可能的奇數狀態。
                int stateJ = state ^ (1<<k);    // 將每一位的二進制翻轉一次。
                ans += count[stateJ];           // 一個奇數的狀態，state 和 stateJ 差一個位元不同。
            }

            count[state]++;                     // 更新當前狀態的出現次數。
        }
        return ans;
    }
};

// XXXXj[XXXXXi]XX

// 第一個情況，全是偶數：
// count[a][i] odd, even 找 count[a][j] odd, even。
// count[b][j] odd, even 找 count[b][j] odd, even。
// count[c][j] odd, even 找 count[c][j] odd, even。
// ...
// 同奇同偶。
// 以 state = 0001001001，表示 a~j 的奇偶。
// 找 state[i] = state[j]。

// 第二個情況，某一個字符是奇數：
// state[i] = 000100100[1]。
// state[j] = 000100100[0]。
// 有一位不同。
// state[j] = state[i] ^ (1<<10)

// Hash + Prefix + state.
// Reference from 【每日一题】1915. Number of Wonderful Substrings, 7/1/2021, https://youtu.be/QiiK-his0IQ.

// ------------------------------------------------------------

// Prefix Sums（前綴和）概念：
// 當需要快速查詢數組中某一區間的元素和時，Prefix Sums可以幫助我們在O(1)的時間複雜度內進行查詢。
//                       i         j
// 原數組：[    -2,   0,  3,  -5,   2,  -1]
// 前綴和：[0,  -2,  -2,  1,  -4,  -2,  -3]
//                   i             j+1
// 區間[i, j]的和 = 3-5+2 = preSum[j+1] - preSum[i] = -2-(-2) = 0

// https://claire-chang.com/2023/05/04/prefix-sums%EF%BC%88%E5%89%8D%E7%B6%B4%E5%92%8C%EF%BC%89%E6%A6%82%E5%BF%B5/.
// https://wansuanfa.com/index.php/719.