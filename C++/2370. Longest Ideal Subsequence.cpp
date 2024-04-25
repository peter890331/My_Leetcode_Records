class Solution {
public:
    int longestIdealString(string s, int k) {
    /*
        queue<char> t;
        if (abs((s[1]-'0')-(s[0]-'0')) <= k)
                t.push(s[0]);
        for (int i=1; i<s.size(); i++){
            // cout<<s[i]-'0'<<endl;
            if (!t.empty() && abs(s[i] - t.back()) <= k){
                // cout<<s[i]<<','<<t.back()<<endl;
                t.push(s[i]);
            }
            else if (t.empty() && abs(s[i] - s[i-1])){
                t.push(s[i-1]);
                t.push(s[i]);
            }
        }
        print(t);
        return t.size();
    }

    void print(queue<char> t){
        while(!t.empty()){
            cout<<t.front()<<',';
            t.pop();
        }
    }
    */

        int n = s.size();
        vector<int> dp(n, 1);       // the longest subsequence ending at i.
        vector<int> prev(26, -1);   // 前面最近的某個ch的位置。

        int ans = 0;
        for (int i=0; i<n; i++){
            for (int ch = max(0, s[i]-'a'-k); ch <= min(25, s[i]-'a'+k); ch++){     //ch為s[i]可以接續的字們。
                int j = prev[ch];                   // 前面最近的某個ch的位置。
                if (j != -1)                        // 如果有找到位置。
                    dp[i] = max(dp[i], dp[j]+1);    // 更新dp。
            }
            prev[s[i]-'a'] = i;                     // 更新s[i]的位置。
            ans = max(ans, dp[i]);                  // the longest subsequence.
        }
        return ans;
    }
};


// dp.
// Reference from 【每日一题】LeetCode 2370. Longest Ideal Subsequence, https://youtu.be/NlwpGpH4nLA.