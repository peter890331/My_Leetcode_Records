class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int result = 0;
        int temp_Time = neededTime[0];
        for (int i=1; i<colors.size(); i++){
            if (colors[i] != colors[i-1]){
                temp_Time = neededTime[i];
            }
            else if (colors[i] == colors[i-1]){
                result += min(temp_Time, neededTime[i]);
                temp_Time = max(temp_Time, neededTime[i]);
            }
        }
        return result;
    }
    // void print(vector<int>& dp){
    //     for (int i=0; i<dp.size(); i++) cout<<dp[i]<<',';
    // }
};

// Reference from LeetCode 每日一題 Daily Challenge 1578. Minimum Time to Make Rope Colorful, https://youtu.be/ijA6KXuDFuc.