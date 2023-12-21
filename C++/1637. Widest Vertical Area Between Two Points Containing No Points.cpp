class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x(points.size());
        for (int i=0; i<points.size(); i++){
            x[i] = points[i][0];
        }
        sort(x.begin(), x.end());
        int result = 0;
        for (int j=1; j<x.size(); j++){
            int temp = x[j] - x[j-1];
            result = max(result, temp);
        }
        return result;
    }
};