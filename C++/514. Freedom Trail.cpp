class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        unordered_map<char, vector<int>> letter2pos;
        for (int i=0; i<m; i++)
            letter2pos[ring[i]].push_back(i);

        for (int pos: letter2pos[key[0]])
            dp[0][pos] = min(dp[0][pos], min(pos, m-pos));

        for (int i=1; i<n; i++){
            for (int cur_pos: letter2pos[key[i]])
                for (int pre_pos: letter2pos[key[i-1]])
                    dp[i][cur_pos] = min(dp[i][cur_pos], dp[i-1][pre_pos] + min(abs(cur_pos - pre_pos), m - abs(cur_pos - pre_pos)));
        }

        int ans = INT_MAX;
        for (int pos: letter2pos[key[n-1]])
            ans = min(ans, dp[n-1][pos]);

        return ans + n;

    }
};


// dp.
// Reference from 【每日一题】514. Freedom Trail, 5/1/2020, https://youtu.be/1ErNzKfRrX8.