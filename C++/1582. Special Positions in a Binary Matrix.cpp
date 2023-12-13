class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int result = 0;
        for (int m=0; m<mat.size(); m++){
                int n = check_row(mat, m);
                if (n >= 0 && check_col(mat, m, n)) result++;
        }
        return result;
    }
    int check_row(vector<vector<int>>& mat, int m){
        int row_count = 0;
        int index;
        for (int i=0; i<mat[0].size(); i++){
            if (mat[m][i] == 1){
                index = i;
                row_count ++;
            };
        }
        return (row_count == 1) ? index : -1;
    }
    int check_col(vector<vector<int>>& mat, int m, int n){
        for (int i=0; i<mat.size(); i++){
            if (mat[i][n] == 1 && i != m) return false;
        }
        return true;
    }
};