class Solution {
public:
    int maxGold = 0;
    vector<int> roww = {1, -1, 0, 0};
    vector<int> coll = {0, 0, -1, 1};

    // 如果grid中沒有0，最大值就是全部金子相加，也就是全部格子都走一遍。
    int checkIfAllZeros(vector<vector<int>>& grid){
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != 0) count += grid[i][j];
                else return 0;
            }
        }

        return count;
    }

    // 遞迴探索四個方向上的移動，並計算獲得金子的總量。
    void backtrack(vector<vector<int>>& grid, int x, int y, int count){
        if(x < 0 || x >= grid.size() || y >= grid[0].size() || y < 0) return;   // 如果當前位置是邊界之外，則直接返回。

        if(grid[x][y]){
            int curr = grid[x][y];
            grid[x][y] = 0;
            count += curr;
            maxGold = max(maxGold, count);
            // 如果當前位置的值不為零，則將該位置的金子數加到 count 中，然後把該位置設為零（表示已經獲得過金子了），並更新最大金子數。

            for(int i = 0; i < 4; i++) {
                int newX = x + roww[i];
                int newY = y + coll[i];
                backtrack(grid, newX, newY, count);
            }
            // 遞迴探索四個方向上的移動，每次移動都呼叫自身。

            grid[x][y] = curr;  // 從某格開始的探索完成後，恢復當前位置的金子數，等待從其他格開始的探索。
        }
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int count = checkIfAllZeros(grid);
        if(count) {
            return count; 
        }
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]) {
                    backtrack(grid, i, j, 0);   // 從某格開始探索。
                }
            }
        }

        return maxGold;
    }
};

// 回溯法（backtracking），暴力解？
// gameboey's solution.