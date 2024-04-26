class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i=0; i<n; i++){
            dp[0][i] = grid[0][i];
        }

        for (int i=1; i<n; i++){
            for (int j=0; j<n; j++){
                int temp = INT_MAX;
                for (int k=0; k<n; k++){
                    if(k!=j){
                        temp = min(temp, grid[i][j] + dp[i-1][k]);
                    }
                    dp[i][j] = temp;
                }
            }
        }

        for (int i=0; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }

        return ans;

        // print(dp);
    }
    /*
    void print(vector<vector<int>>& dp){
        int n = dp.size();
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cout<<dp[i][j]<<',';
            }
            cout<<endl;
        }
    }
    */
};