class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int R = grid.size();        // rows size.
        int C = grid[0].size();     // cols size.

        // 把每個rows的開頭第一個bit都先轉成1，這在答案中影響最大。
        for (int i=0; i<R; i++){
            if (grid[i][0] == 0){
                for (int j=0; j<C; j++){
                    grid[i][j] = 1-grid[i][j];
                }
            }
        }

        // 建立一個cols個數的vector，用來計算所有rows中每個bit共有多少個1。
        vector<int> cols(C, 0);

        // 計算所有rows中每個bit共有多少個1。
        // ex:
        //      0011
        //      1010
        //      1100
        //      ----
        //      2121
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                cols[j] += grid[i][j];
            }
        }

        // 如果cols vector中某個bit的1的數量，少於將這個cols翻轉一次，則翻轉，這樣可以保證每個cols都有最多的1。
        for (int i=0; i<C; i++){
            if (cols[i] < R-cols[i]){
                // for (j=0; j<R-1; j++){
                //     grid[i][j] = 1-grid[i][j];
                // }
                cols[i] = R-cols[i];
            }
        }

        // 計算ans。
        int ans = 0;
        for (int i=0; i<C; i++){
            ans *= 2;
            ans += cols[i];
        }

        return ans;
    }
};

// Greedy algorithm？
// Reference from 861. Score After Flipping Matrix - Day 13/31 Leetcode May Challenge, https://youtu.be/FTFYzQkYCt4.