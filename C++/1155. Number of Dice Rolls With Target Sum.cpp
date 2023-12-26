class Solution {
public:
    const int mod = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1)); // 建立二維dp，rows是用n個骰子，cols是targets，可以參考Reference的youtube影片。
        // print(dp);
        return recursive(dp, n, k, target);
    }

private:
    int recursive(vector<vector<int>>& dp, int n, int k, int target){
        if (n==0 && target==0) return 1;                        // 使用0個骰子投出總和為0，有一種可能，且return權限先於下行。
        if (n==0 || target<=0) return 0;                        // 使用0個骰子或投出總和為負數，沒有可能。
        if (dp[n][target] != -1) return dp[n][target] % mod;    // 當可能數不等於-1，為已經計算覆寫過，直接回傳。
        int temp = 0;
        for (int j=1; j<=k; j++){
            // temp += recursive(dp, n-1, k, target-j);
            // temp = temp % mod;
            temp = (temp + recursive(dp, n-1, k, target-j)) % mod; 
            // 使用n個骰子投出總和為target，等於使用n-1個骰子投出(target-1)+(target-2)+...+(target-k)的總和，可以參考Reference的youtube影片。
            // 要在每次的相加都先取模，以免Runtime error。
        }
        dp[n][target] = temp % mod;
        // print(dp);
        return dp[n][target];
    }
    void print(vector<vector<int>>& dp){
        for (int m=0; m<dp.size(); m++){
            for (int n=0; n<dp[0].size(); n++){
                cout<<dp[m][n]<<',';
            }
            cout<<endl;
        }
        cout<<"--------------"<<endl;
    }
};

// Dynamic programming.
// Reference from MarkSPhilip31's solution.
// Reference from 花花酱 LeetCode 1155. Number of Dice Rolls With Target Sum - 刷题找工作 EP263, https://youtu.be/J9s7402s5FA.