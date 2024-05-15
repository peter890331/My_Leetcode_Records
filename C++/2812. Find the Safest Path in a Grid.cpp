using PII = pair<int, int>;
class Solution {
    vector<PII> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<PII> q;

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1) q.push({i, j});    // 初始隊列，包含grid中所有thief。
            }
        }
        
        // 拓樸排序結構的BFS，剝洋蔥？
        // 修改grid，將grid[i][j]修改成從(i, j)到其最近的thief的距離再加1(再加1的原因是原本的thief就是1，要與其做出區別)。
        // grid[i][j]: the distance from (i, j) to its nearest thief + 1.
        // 1 0 0    1 2 3
        // 0 0 0 => 2 3 2
        // 0 0 1    3 2 1

        while(!q.empty()){

            auto [x, y] = q.front();
            q.pop();

            for (int i=0; i<4; i++){                            // 往四個方向走。
                int x_ = x + dir[i].first;
                int y_ = y + dir[i].second;
                if (x_<0 || x_>=n || y_<0 || y_>=n) continue;   // 出界。
                if (grid[x_][y_] != 0) continue;                // 原本就是thief，或是已被訪問過。
                grid[x_][y_] = grid[x][y] + 1;                  // 更新grid數值，從走來的thief再加1。
                q.push({x_, y_});                               // 新增到隊列，讓後續繼續更新。
            }
        }

        // Binary search.
        // 猜在安全路徑中，每格都能夠大於的最大d是多少。
        // 0 0 0 1    4 3 2 1
        // 0 0 0 0    3 4 3 2
        // 0 0 0 0 => 2 3 4 3
        // 1 0 0 0    1 2 3 4
        // 最大的d=2，grid[0][0]、grid[0][1]、grid[1][1]、grid[1][2]、grid[2][2]、grid[3][2]、grid[3][3]都大於2。

        int left = 0, right = 2*n;  // grid中最大的曼哈頓距離是2n。

        while(left < right){

            int mid = right-(right-left)/2;             // 因為是int，2-0.5=2。
            cout<<left<<','<<right<<','<<mid<<endl;
            if (gridfoundpath(mid, grid))
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }

    // BFS。
    // 找尋grid中是否有每格都大於d的安全路徑。
    bool  gridfoundpath(int d, vector<vector<int>>& grid){

        int n = grid.size();
        vector<vector<int>> visited(n, vector(n, 0));

        if (grid[0][0]<=d || grid[n-1][n-1]<=d) return false;

        queue<PII> q;
        q.push({0,0});
        visited[0][0] = 1;

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for (int i=0; i<4; i++){                            // 往四個方向走。
                int x_ = x + dir[i].first;
                int y_ = y + dir[i].second;
                if (x_<0 || x_>=n || y_<0 || y_>=n) continue;   // 出界。
                if (visited[x_][y_] != 0) continue;             // 已被訪問過。
                if (grid[x_][y_] <= d) continue;                // grid[i][j]小於等於猜測的d。

                if (x_ == n-1 && y_ == n-1) return true;        // 到終點。

                visited[x_][y_] = 1;                            // 已被訪問過。
                q.push({x_, y_});                               // 新增到隊列，讓後續繼續更新。
            }
        }

        return false;                                           // 沒有找到每格都大於d的安全路徑。

    }
};

// Reference from 【每日一题】LeetCode 2812. Find the Safest Path in a Grid, https://youtu.be/OjzQ6TmMh6k.