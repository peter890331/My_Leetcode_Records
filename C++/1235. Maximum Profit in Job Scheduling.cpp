class Solution {
public:
    static bool mycompare(vector<int>&a, vector<int>&b) {
    //compare function，用於sort的第三個變數，修改排列順序
    return a[1] < b[1];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> jobs;
        for (int i=0; i<n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), mycompare);

        // for (int i=0; i<n; i++){
        //     cout<<jobs[i][1]<<',';
        // }

        map<int, int> dp; // dp[t] -> porfit[t]
        // dp[i] = dp[j] + porfit[i] or dp[i-1] 
        int ret = 0;
        for (int i=0; i<n; i++){
            int cur = ret;                                              // if dp[i] = dp[i-1]
            auto iter = dp.upper_bound(jobs[i][0]);
            if (iter != dp.begin()){                                    
                // if dp.upper_bound找得到第一個大於dp[i]的startTime的endTime，
                // 再使用prev(iter, 1)往前推一位即是最後一個小於dp[i]的startTime的endTime。
                cur = max(cur, prev(iter, 1)->second + jobs[i][2]);     // if dp[i] = dp[j] + porfit[i]
            }
            else{                                                       // if dp.upper_bound找不到解，已經是dp.begin()，沒辦法往前推一位。
                cur = max(cur, jobs[i][2]);
            }
            dp[jobs[i][1]] = cur;

            ret = max(ret, cur);
        }
        return ret;
    }
};

// Reference fom 【每日一题】1235. Maximum Profit in Job Scheduling, 1/9/2021, https://youtu.be/0C7re8lam7M