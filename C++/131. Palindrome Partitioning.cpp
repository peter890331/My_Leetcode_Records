class Solution {
    int dp[16][16];
    vector<vector<string>> ans;
    int n;
    string s;
public:
    vector<vector<string>> partition(string s) 
    {
        this->s = s;
        n = s.size();
        
        for (int i=0; i<n; i++)
            dp[i][i] = 1;

        for (int i=0; i+1<n; i++)
            dp[i][i+1] = s[i]==s[i+1];

        for (int len=3; len<=n; len++)
            for (int i=0; i+len-1<n; i++)
            {
                int j = i+len-1;
                if (s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = 0;
            }

        vector<string> ans_;
        dfs(0, ans_);

        return ans;
    }

    void dfs(int i, vector<string>& ans_)
    {
        if (i==n)
        {
            ans.push_back(ans_);
            return;
        } 
        for (int j=i; j<n; j++)
        {
            if (dp[i][j])
            {
                ans_.push_back(s.substr(i, j-i+1));
                dfs(j+1, ans_);
                ans_.pop_back();
            }
        }
    }
};

// dp + dfs.
// Reference from 【每日一题】131. Palindrome Partitioning, 5/9/2021, https://youtu.be/OqYHNDmG13g.