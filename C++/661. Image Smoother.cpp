class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int sum = 0;
                int count = 0;
                for (int i_=max(0,i-1); i_<min(m,i+2); i_++){
                    for (int j_=max(0,j-1); j_<min(n,j+2); j_++){
                        sum += img[i_][j_];
                        count ++;
                    }
                }
                result[i][j] = sum / count;
            }
        }
        return result;
    }
};