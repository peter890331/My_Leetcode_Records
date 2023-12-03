class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result = 0;
        for (int i=1; i<points.size(); i++){
            result += step_count(points[i - 1], points[i]);

        }
        return result;
    }

    int step_count(vector<int>& a, vector<int>& b){
        if (a[0] == b[0]) return abs(a[1] - b[1]);
        else if (a[1] == b[1]) return abs(a[0] - b[0]);
        else return max(abs(a[0] - b[0]), abs(a[1] - b[1]));
    }
};