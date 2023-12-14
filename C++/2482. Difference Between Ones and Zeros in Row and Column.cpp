class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        vector<int> Rowi(m, 0);       // Rowi(1)
        vector<int> Coli(n, 0);       // Coli(1)
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j]==1){
                    Rowi[i]++;
                    Coli[j]++;
                }
            }
        }
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                result[i][j] = Rowi[i] + Coli[j] - (m-Rowi[i]) - (n-Coli[j]);
            }
        }
        return result;
    }
};